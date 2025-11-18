#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constant.h"
#include "variable.h"
#include "grid.h"

// Timer structure
typedef struct {
    struct timespec start;
    struct timespec end;
} Timer;

// Start timer
void timer_start(Timer *t) {
    clock_gettime(CLOCK_MONOTONIC, &t->start);
}

// Stop time and diff
double timer_elapsed(Timer *t) {
    clock_gettime(CLOCK_MONOTONIC, &t->end);
    return (t->end.tv_sec - t->start.tv_sec)
           + (t->end.tv_nsec - t->start.tv_nsec) * 1e-9;
}

int main(void){      
    nx = 500;
    ny = 500;
    nz = 500;

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

    Timer t;
    timer_start(&t);
    grid_init();
    double elapsed_grid = timer_elapsed(&t);
    printf("time = %f[sec]\n", elapsed_grid);
    //printf("dx=%f, dy=%f, dz=%f\n", dx, dy, dz);


    //printf("Mbh=%6.4f[g]\n", solarmass2g(Mbh));
    grid_free();
    return 0;

}

