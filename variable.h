#ifndef variable_h
#define variable_h

// Variable name
extern int nx, ny, nz; //Grid number
extern double xmin, xmax; // X range
extern double ymin, ymax; // Y range
extern double zmin, zmax; // Z range
extern double dx, dy, dz; // Grid space

extern double gcon[4][4]; //Metric contravariant
extern double gcov[4][4]; //Metric covariant


extern double rho, pg; // Gas mass density, Gas pressure
extern double vx, vy, vz; // gas velocity

extern double RHOMIN, PGMIN; // Minimum limit?

extern double Mbh, bh_a; // BH mass, BH spin
#endif
