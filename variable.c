#include "variable.h"

int nx, ny, nz; //Grid number
double xmin, xmax; // X range
double ymin, ymax; // Y range
double zmin, zmax; // Z range
double dx, dy, dz; // Grid space

double gcon[4][4]; //Metric contravariant
double gcov[4][4]; //Metric covariant


double rho, pg; // Gas mass density, Gas pressure
double vx, vy, vz; // gas velocity

double RHOMIN, PGMIN; // Minimum limit?

double Mbh, bh_a; // BH mass, BH spin
