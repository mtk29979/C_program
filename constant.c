#include "constant.h"

struct Constant pc = {
    //Constant cgs unit
    .c = 2.99792458e10, //Light speed
    .G = 6.67430e-8, //Gravitational constant
    .Msun = 1.988e33, //Solar mass
    .kb = 1.3807e-16, //Boltzman constant
    .mp = 1.6726e-24, //Proton mass
    .me = 9.1094e-28, //Electron mass
    .h = 6.6261e-27, //Plank constant
    .pi = 3.14159265358979, //Pi
    .gamma = 5.0/3.0, //Specific heat ratio
    .mu = 0.5 //mean molecular weight
};
