#ifndef GRID_H
#define GRID_H

extern double dx, dy, dz; // Grid interval
extern double *x, *y, *z;

void grid_init(void); 
void grid_free(void);

#endif
