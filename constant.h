#ifndef constant_h
#define constant_h

//Constant cgs unit
static const double c = 2.99792458e10; //Light speed
static const double G = 6.67430e-8; //Gravitational constant
static const double Msun = 1.988e33; //Solar mass
static const double kb = 1.3807e-16; //Boltzman constant
static const double mp = 1.6726e-24; //Proton mass
static const double me = 9.1094e-28; //Electron mass
static const double h = 6.6261e-27; //Plank constant
static const double pi = 3.14159265358979; //Pi
static const double gamma = 5.0/3.0; //Specific heat ratio
static const double mu = 0.5; //mean molecular weight

static inline double cm2rg(double Mbh){
  return (G*Mbh) / (c*c);
}

static inline double s2tg(double Mbh){
  return (G*Mbh) / (c*c*c);
}

static inline double solarmass2g(double Mbh){
  return Mbh * Msun;
}

static inline double c2cms(double v){
  return v * c;
}
#endif
