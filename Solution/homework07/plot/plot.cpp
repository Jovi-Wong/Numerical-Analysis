#include "plot.h"

double condf(double x)
{
	return (x/(exp(x)-1.0));
}

double condA(double x)
{
	return (exp(x)-1.0)*(2.0+1.0/(1.0-exp(-x)))/x;
}
