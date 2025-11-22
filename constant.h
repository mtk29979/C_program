#ifndef CONSTANT_H
#define CONSTANT_H

//Constant cgs unit
struct Constant{
    const double c; //Light speed
    const double G; //Gravitational constant
    const double Msun; //Solar mass
    const double kb; //Boltzman constant
    const double mp; //Proton mass
    const double me; //Electron mass
    const double h; //Plank constant
    const double pi; //Pi
    const double gamma; //Specific heat ratio
    const double mu; //mean molecular weight
};
extern struct Constant pc;

static inline double cm2rg(double Mbh){
  return (pc.G*Mbh) / (pc.c*pc.c);
}

static inline double s2tg(double Mbh){
  return (pc.G*Mbh) / (pc.c*pc.c*pc.c);
}

static inline double solarmass2g(double Mbh){
  return Mbh * pc.Msun;
}

static inline double c2cms(double v){
  return v * pc.c;
}
#endif
