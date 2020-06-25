#include "bisection.h"

double func1(double x)
{	
	return (2.0/3.0*(sqrt(fabs(x))+sqrt(3-x*x)));
}

double func2(double x)
{
	return (2.0/3.0*(sqrt(fabs(x))-sqrt(3-x*x)));
}

