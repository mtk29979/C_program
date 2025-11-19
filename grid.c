#include "grid.h"
#include "initval.h"
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
double dx, dy, dz; //Grid interval
double *x, *y, *z; //Grid



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
}

void grid_free(void){
    free(x);
    free(y);
    free(z);
}
