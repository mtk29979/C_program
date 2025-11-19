#ifndef INITVAL_H
#define INITVAL_H

// Variable name
extern int nx, ny, nz; //Grid number
extern double xmin, xmax; // X range
extern double ymin, ymax; // Y range
extern double zmin, zmax; // Z range

extern double rho, pg; // Gas mass density, Gas pressure
extern double vx, vy, vz; // gas velocity

extern double RHOMIN, PGMIN; // Minimum limit?

extern double Mbh, bh_a; // BH mass, BH spin
extern double aa; //bh_a*bh_a

void initialize(void);
#endif
