#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001
#define SQRT_2 1.41421356237

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(double, double, double, double);
char dt1b(double, double, double, double);

double dt2a(double, double, double, int, int);
double dt2b(double, double, double, int, int);

/* Write the prototype of the functions implementing the decision trees for the third problem */
double dt3a(double, double, int, int, int);
double dt3b(double, double, int, int, int);					/* Two real numbers, one binary, one hexadecimal, and one 32 base*/

double bigger(double, double);
double smaller(double, double);

#endif /* _UTIL_H_ */
