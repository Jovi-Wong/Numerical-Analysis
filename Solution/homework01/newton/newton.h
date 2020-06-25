#ifndef _JOVI_WONG_
#define _JOVI_WONG_

#include <iostream>
#include <cmath>
#include <fstream>
#define _USE_MA:TH_DEFINES

double f(double);

double df(double);

class NewtonMethod
{
private:
	double x0;
public:
	double (*f)(double);
	double (*df)(double);
	NewtonMethod(double (*func)(double), double (*dfunc)(double), double x);
	double newton(int M, double eps);
};

#endif
