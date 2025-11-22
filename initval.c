#include "initval.h"
#include "constant.h"
#include "grid.h"
#include <stdlib.h>
#include <omp.h>

struct Initval init;

// Don't use variables of grid.h in initialize()!
// It is included for only init_condition().
void initialize(void){
    init.nx = 10;
    init.ny = 10;
    init.nz = 1;

    init.xmin = -10.0;
    init.xmax = 10.0;

    init.ymin = -10.0;
    init.ymax = 10.0;

    if (init.nz == 1){
        init.zmin = 0;
        init.zmax = 0;
    }
    else{
        init.zmin = -10.0;
        init.zmax = 10.0;
    }
    
    init.Mbh = 10; //Solarmass
    init.bh_a = 0.9; //Spin parameter
    init.aa = init.bh_a*init.bh_a; //Don't change 

    init.norm_rho = 1e-8; // g/cm^3
    init.norm_energy = init.norm_rho * pc.c*pc.c; // erg/cm^3 Don't change

    init.RHOMIN = 1e-20;
    init.PGMIN  = 1e-20;
}

// You can use variables of grid.h.
void init_condition(void){
    init.val0 = malloc(init.nx*init.ny*init.nz * sizeof(*init.val0)); //For GRHD, not GRRHD

    //////////////////////////////
    // You don't always have to use this below variable.
    // It is just framework.
    double rho0 = 1e-8; // g/cm^3
    double pg0 = 1e+5; // dyn/cm^2
    double vx0 = 0.1; // c(Light speed)
    double vy0 = 0.0; // c
    double vz0 = 0.0; // c
    //////////////////////////////
    
#pragma omp parallel for collapse(3)
    for(int k=0; k<init.nz; k++){
        for(int j=0; j<init.ny; j++){
            for(int i=0; i<init.nx; i++){
                int idx = i + init.nx*(j + init.ny*k);
                init.val0[idx][0] = rho0 / init.norm_rho;
                init.val0[idx][1] = vx0;
                init.val0[idx][2] = vy0;
                init.val0[idx][3] = vz0;
                init.val0[idx][4] = pg0 / init.norm_energy;
            }
        }
    }
}

void free_init_condition(){
    free(init.val0);
    init.val0 = NULL;
}
