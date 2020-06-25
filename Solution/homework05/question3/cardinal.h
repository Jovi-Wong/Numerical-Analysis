#ifndef JOVI_WONG
#define JOVI_WONG

#include <iostream>
#include <fstream>
#include <cmath>
#include <lapacke.h>

double B2(int i, double x);

double B3(int i, double x);

double function(double x);

class quadratic_cardinal
{
public:
	quadratic_cardinal(int n, double(*f)(double));
	double(*func)(double);
	friend double B2(int i, double x);
	double S(double x);
	void plot(void);
private:
	double* a;
	int N;
};

class cubic_cardinal
{
public:
	cubic_cardinal(int n, double(*f)(double), double d1, double dN);
	double(*func)(double);
	double S(double x);
	friend double B3(int i, double x);
	void plot(void);
private:
	double df1;
	double dfN;
	double* a;
	int N;
	int init;
};
#endif


