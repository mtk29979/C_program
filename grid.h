#ifndef GRID_H
#define GRID_H

struct Grid{
    double dx, dy, dz; // Grid interval
    double *x, *y, *z;
};

extern struct Grid grid;
void grid_init(void); 
void grid_free(void);

#endif
