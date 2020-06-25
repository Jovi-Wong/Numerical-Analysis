#include "compute.h"

double f(double x)
{
	return (pow(x,8)-8.0*pow(x,7)+28.0*pow(x,6)-56.0*pow(x,5)+70.0*pow(x,4)-56.0*pow(x,3)+28.0*pow(x,2)-8.0*x+1.0);
};

double g(double x)
{
	return ((((((((x-8.0)*x+28.0)*x-56.0)*x+70.0)*x-56.0)*x+28.0)*x-8.0)*x+1.0);
};

double h(double x)
{
	return (pow(x-1.0,8));
};
