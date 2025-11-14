#include <stdio.h>
#include <stdlib.h>
#include "constant.h"
#include "variable.h"

int main(void){      
    nx = 100;
    ny = 100;
    nz = 1;

    xmin = -100.0;
    xmax = 100.0;
    dx   = (xmax-xmin+1) / nx;

    ymin = -100.0;
    ymax = 100.0;
    dy   = (ymax-ymin+1) / ny;

    if (nz == 1){
        zmin = 0;
        zmax = 0;
        dz   = 0;
    }
    else{
        zmin = -100.0;
        zmax = 100.0;
        dz   =(zmax-zmin+1) / nz;
    }
    
    Mbh = 10; //Solarmass
    bh_a = 0.0; //Spin parameter

    RHOMIN = 1e-20;
    PGMIN  = 1e-20;

    //printf("Mbh=%6.4f[g]\n", solarmass2g(Mbh));
    return 0;

}
