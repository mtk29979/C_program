#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constant.h"
#include "initval.h"
#include "grid.h"
#include "metric.h"

////////////////////////////////
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
//////////////////////////////////

int main(void){      
    initialize(); // determine basic value like nx, xmin, and so on <initval.c>

    Timer t; //time measure(If you finish making code, delete it) 
    timer_start(&t); // time measure(If you finish making code, delete it) 

    grid_init(); // Using initialize() result, make grid <grid.c>
                 
    init_condition(); // Using grid_init() result, make initial condition <initval.c>

    Kerr_metric(); // Make Kerr_metric(g_contravariatn, g_covariant) <metric.c>
                   
    check_metric_inverse(); // Debug


    double elapsed_grid = timer_elapsed(&t); //time measure(If you finish making code, delete it) 
    printf("time = %f[sec]\n", elapsed_grid); //time measure(If you finish making code, delete it) 
    //printf("dx=%f, dy=%f, dz=%f\n", dx, dy, dz);


    //printf("Mbh=%6.4f[g]\n", solarmass2g(Mbh));
    Kerr_metric_free();
    grid_free();
    free_init_condition();
    return 0;

}

