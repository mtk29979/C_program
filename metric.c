#include "grid.h"
#include "metric.h"
#include "initval.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
double (*gcov)[4][4] = NULL;
double (*gcon)[4][4] = NULL;
 

//Calculate r(not x*x + y*y + z*z!) 
double cal_r(double x, double y, double z){
    double RR = x*x + y*y + z*z;
    double r = sqrt(((RR-init.aa) + sqrt((RR-init.aa)*(RR-init.aa) + 4.0*init.aa*z*z)) / 2.0);
    return r;
}

//Minkowsky metric
static const double eta[4][4] = {
    {-1,0,0,0},
    { 0,1,0,0},
    { 0,0,1,0},
    { 0,0,0,1}
};

// Make Kerr metric (g_contravariant and g_covariant)
void Kerr_metric(void){
    gcov = malloc(init.nx*init.ny*init.nz * sizeof(*gcov));
    gcon = malloc(init.nx*init.ny*init.nz * sizeof(*gcon));

#pragma omp parallel for collapse(3)
        for(int k=0; k<init.nz; k++){
            for(int j=0; j<init.ny; j++){
                for(int i=0; i<init.nx; i++){
                    int idx = i + init.nx*(j + init.ny*k);
                    double r = cal_r(grid.x[i], grid.y[j], grid.z[k]);
                    //printf("x[%d]=%f, y[%d]=%f, z[%d]=%f, r=%f\n", i, grid.x[i], j, grid.y[j], k, grid.z[k], r); //debug
                    double denom = r*r + init.aa;
                    double lcov[4] = {
                        1.0, 
                        (r*grid.x[i] + init.bh_a*grid.y[j]) / denom,
                        (r*grid.y[j] - init.bh_a*grid.x[i]) / denom,
                        grid.z[k] / r
                    };

                    double lcon[4] = {
                        -1.0, 
                        (r*grid.x[i] + init.bh_a*grid.y[j]) / denom,
                        (r*grid.y[j] - init.bh_a*grid.x[i]) / denom,
                        grid.z[k] / r
                    };

                    double factor = 2*r*r*r / (r*r*r*r + init.aa*grid.z[k]*grid.z[k]);
                    for(int ii=0; ii<4; ii++){
                        for(int jj=0; jj<4; jj++){
                            gcov[idx][ii][jj] = eta[ii][jj] + 
                                factor*lcov[ii]*lcov[jj];

                            gcon[idx][ii][jj] = eta[ii][jj] - 
                                factor*lcon[ii]*lcon[jj];
                        }
                    }
                }
            }
        }
}

// For Debug
void check_metric_inverse(void){
    double tol = 1e-12; // allow error
    int error_flag = 0;

    for(int k=0;k<init.nz;k++){
        for(int j=0;j<init.ny;j++){
            for(int i=0;i<init.nx;i++){
                int idx = i + init.nx*(j + init.ny*k);

                for(int mu=0; mu<4; mu++){
                    for(int nu=0; nu<4; nu++){
                        double sum = 0.0;
                        for(int lam=0; lam<4; lam++){
                            sum += gcov[idx][mu][lam] * gcon[idx][lam][nu];
                        }
                        if(fabs(sum - (mu==nu ? 1.0 : 0.0)) > tol){
                            printf("Mismatch at idx=%d, mu=%d, nu=%d, sum=%e\n",
                                   idx, mu, nu, sum);
                            error_flag = 1;
                        }
                    }
                }
            }
        }
    }
    if(!error_flag) printf("All gcov * gcon = identity within tol=%e\n", tol);
}

void Kerr_metric_free(void){
    free(gcov);
    free(gcon);
}
