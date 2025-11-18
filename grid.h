#ifndef grid_h
#define grid_h

extern double dx, dy, dz; // Grid interval
extern double *x, *y, *z;

void grid_init(void); 
void grid_free(void);

#endif
