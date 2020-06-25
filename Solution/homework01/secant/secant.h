#ifndef _JOVI_WONG_
#define _JOVI_WONG_
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#define _USE_MATH_DEFINES

double f1(double);

double f2(double);

double f3(double);

class SecantMethod
{
private:
	double x0;
	double x1;
	double (*f)(double);
public:
	SecantMethod(double (*func)(double), double x, double y);
	int secant(int M, double delta, double eps);
};

#endif
