#ifndef JOVI_WONG
#define JOVI_WONG

#include <iostream>
#include <fstream>
#include <cmath>
#include <lapacke.h>

double f(double x);

int cubic_spline(int N, double(*func)(double));

#endif
