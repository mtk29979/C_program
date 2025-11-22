#ifndef INITVAL_H
#define INITVAL_H

// Variable name
struct Initval{
    int nx, ny, nz; //Grid number
    double xmin, xmax; // X range
    double ymin, ymax; // Y range
    double zmin, zmax; // Z range
    
    double norm_rho, norm_energy; // normalization
    double RHOMIN, PGMIN; // Minimum limit?
    
    double Mbh, bh_a; // BH mass, BH spin
    double aa; //bh_a*bh_a
    
    double (*val0)[5]; // Initial condition
};

extern struct Initval init;

void initialize(void);
void init_condition(void);
void free_init_condition(void);
#endif
