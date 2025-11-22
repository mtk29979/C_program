#include "grid.h"
#include "initval.h"
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

struct Grid grid;

void grid_init(void){
	grid.dx = (init.xmax-init.xmin) / init.nx;
	grid.dy = (init.ymax-init.ymin) / init.ny;
	grid.dz = (init.zmax-init.zmin) / init.nz;

	// x,y,z allocate
	grid.x = malloc(init.nx * sizeof(double));
	grid.y = malloc(init.ny * sizeof(double));
    grid.z = malloc(init.nz * sizeof(double));

	// Enter
#pragma omp parallel for
	for(int i=0; i<init.nx; i++){
        grid.x[i] = init.xmin + (i+0.5)*grid.dx;
	}
#pragma omp parallel for
    for(int j=0; j<init.ny; j++){
        grid.y[j] = init.ymin + (j+0.5)*grid.dy;
    }
#pragma omp parallel for
    for(int k=0; k<init.nz; k++){
        grid.z[k] = init.zmin + (k+0.5)*grid.dz;
        }
}

void grid_free(void){
    free(grid.x);
    free(grid.y);
    free(grid.z);
    grid.x = NULL;
    grid.y = NULL;
    grid.z = NULL;
}
