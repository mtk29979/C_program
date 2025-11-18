#include "grid.h"
#include "variable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
double dx, dy, dz; //Grid interval
double *x, *y, *z; //Grid

//Calculate r(not x*x + y*y + z*z!)
void cal_r(double *x, double *y, double *z, double *r){
    for(int k=0; k<nz; k++){
        for(int j=0; j<ny; j++){
            for(int i=0; i<nx; i++){
                int idx = i + nx*(j + ny*k);
                double RR = x[i]*x[i] + y[j]*y[j] + z[k]*z[k];
                r[idx] = sqrt(((RR-aa) + sqrt((RR-aa)*(RR-aa) + 4.0*aa*z[k]*z[k])) / 2.0);
            }
        }
    }
}

//Calculate r(not x*x + y*y + z*z!) for MP
double cal_r_MP(double x, double y, double z){
    double RR = x*x + y*y + z*z;
    double r = sqrt(((RR-aa) + sqrt((RR-aa)*(RR-aa) + 4.0*aa*z*z)) / 2.0);
    return r;
}

void Kerr_metric(double *x, double *y, double *z){
    double *r;
    r = malloc(nx*ny*nz * sizeof(double));

#ifdef _OPENMP
    if (nz == 1){
#pragma omp parallel for collapse(2)
        for(int j=0; j<ny; j++){
            for(int i=0; i<nx; i++){
                int idx = i + nx*j;
                r[idx] = cal_r_MP(x[i], y[j], z[0]);
            }
        }
    }
    else{
#pragma omp parallel for collapse(3)
        for(int k=0; k<nz; k++){
            for(int j=0; j<ny; j++){
                for(int i=0; i<nx; i++){
                    int idx = i + nx*(j + ny*k);
                    r[idx] = cal_r_MP(x[i], y[j], z[k]);
                }
            }
        }
    }
#else
    cal_r(x, y, z, r);
#endif

   // for(int i=0; i<nx*ny*nz; i++){
   //     printf("r[%d] = %f\n", i, r[i]);
   // }
    free(r);
}


void grid_init(void){
	dx = (xmax-xmin) / nx;
	dy = (ymax-ymin) / ny;
	dz = (zmax-zmin) / nz;

	// x,y,z allocate
	x = malloc(nx * sizeof(double));
	y = malloc(ny * sizeof(double));
    z = malloc(nz * sizeof(double));

	// Enter
#pragma omp parallel for
	for(int i=0; i<nx; i++){
        x[i] = xmin + (i+0.5)*dx;
	}
#pragma omp parallel for
    for(int j=0; j<ny; j++){
        y[j] = ymin + (j+0.5)*dy;
    }
#pragma omp parallel for
    for(int k=0; k<nz; k++){
        z[k] = zmin + (k+0.5)*dz;
        }

    Kerr_metric(x, y, z);
}

void grid_free(void){
    free(x);
    free(y);
    free(z);
}
