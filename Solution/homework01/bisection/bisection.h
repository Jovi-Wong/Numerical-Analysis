#ifndef _JOVI_WONG_
#define _JOVI_WONG_
#include <iostream>
#include <cmath>
#include <fstream>
#define _USE_MATH_DEFINES

class ScalarFunc
{
public:
	ScalarFunc(double (*func)(double), double x, double y);
	double a;
	double b;
	double (*f)(double);
	friend void bisect(ScalarFunc& f1, double eps, double delta, int M);	
};

double func1(double);

double func2(double);

double func3(double);

double func4(double);

void bisect(ScalarFunc&, double, double, int);
#endif

