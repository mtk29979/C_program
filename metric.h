#ifndef METRIC_H
#define METRIC_H
extern double (*gcov)[4][4]; //Kerr metric covariant
extern double (*gcon)[4][4]; //Kerr metric contravariant
void Kerr_metric(void);
void check_metric_inverse(void); 
void Kerr_metric_free(void);
#endif
