#ifndef _JOVI_WONG_
#define _JOVI_WONG_

#include <iostream>
#include <cmath>
#include <lapacke.h>

double u1(double x);

double u2(double x);

double u3(double x);

double func(double x);

double InnerProduct(double (*u)(double), double (*v)(double));

#endif
