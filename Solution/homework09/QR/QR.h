#ifndef _JOVI_WONG_
#define _JOVI_WONG_

#include <iostream>
#include <cmath>
#include <lapacke.h>
#include <memory>
#include <cstring>
double u(int n, double x);

int qr(double* const _Q, double* const _R, double* const _A, int _m, int _n);

int trans(double* A, int m, int n, double* AT);

#endif
