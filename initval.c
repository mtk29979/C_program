#include "initval.h"

int nx, ny, nz; //Grid number
double xmin, xmax; // X range
double ymin, ymax; // Y range
double zmin, zmax; // Z range

double rho, pg; // Gas mass density, Gas pressure
double vx, vy, vz; // gas velocity

double RHOMIN, PGMIN; // Minimum limit?

double Mbh, bh_a; // BH mass, BH spin
double aa; //bh_a*bh_a                 

void initialize(void){
    nx = 250;
    ny = 250;
    nz = 250;

    xmin = -100.0;
    xmax = 100.0;

    ymin = -100.0;
    ymax = 100.0;

    if (nz == 1){
        zmin = 0;
        zmax = 0;
    }
    else{
        zmin = -100.0;
        zmax = 100.0;
    }
    
    Mbh = 10; //Write solarmass unit
    bh_a = 0.0; //Spin parameter
    aa = bh_a*bh_a; 

    RHOMIN = 1e-20;
    PGMIN  = 1e-20;
}
