#include "grid.h"
#include "metric.h"
#include "initval.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
double (*gcov)[4][4] = NULL;


//Calculate r(not x*x + y*y + z*z!) 
double cal_r(double x, double y, double z){
    double RR = x*x + y*y + z*z;
    double r = sqrt(((RR-aa) + sqrt((RR-aa)*(RR-aa) + 4.0*aa*z*z)) / 2.0);
    return r;
}

//Minkowsky metric
static const double eta[4][4] = {
    {-1,0,0,0},
    { 0,1,0,0},
    { 0,0,1,0},
    { 0,0,0,1}
};

void Kerr_metric(void){
    gcov = malloc(nx*ny*nz * sizeof(*gcov));

#pragma omp parallel for collapse(3)
        for(int k=0; k<nz; k++){
            for(int j=0; j<ny; j++){
                for(int i=0; i<nx; i++){
                    int idx = i + nx*(j + ny*k);
                    double r = cal_r(x[i], y[j], z[k]);
                    double denom = r*r + aa;

                    double ltmp[4] = {
                        1, 
                        (r*x[i] + bh_a*y[j]) / denom,
                        (r*y[j] - bh_a*x[i]) / denom,
                        z[k] / r
                    };

                    double factor = 2*r*r*r / (r*r*r*r + aa*z[k]*z[k]);
                    for(int ii=0; ii<4; ii++){
                        for(int jj=0; jj<4; jj++){
                            gcov[idx][ii][jj] = eta[ii][jj] + 
                                factor*ltmp[ii]*ltmp[jj];
                        }
                    }
                }
            }
        }

   // for(int i=0; i<nx*ny*nz; i++){
   //     printf("r[%d] = %f\n", i, r[i]);
   // }
}

void Kerr_metric_free(void){
    free(gcov);
}
