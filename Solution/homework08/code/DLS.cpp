#include "DLS.h"

double x[21] = {0.0,0.5,1.0,1.5,2.0,2.5,3.0,
		3.5,4.0,4.5,5.0,5.5,6.0,6.5,
		7.0,7.5,8.0,8.5,9.0,9.5,10.0};

double y[21] = {2.9,2.7,4.8,5.3,7.1,7.6,7.7,  		
		7.6,9.4,9.0,9.6,10.0,10.2,9.7,
		8.3,8.4,9.0,8.3,6.6,6.7,4.1}; 		
	
double u1(double x)
{
	return 1.0;
}

double u2(double x)
{
	return x;
}

double u3(double x)
{
	return x*x;
}

double func(double x)
{
	int i = x/0.5;
	return y[i];
}

double InnerProduct(double (*u)(double), double (*v)(double))
{
	double ans=0.0;
	
	for(int i=0; i<21; i++)
	{
		double temp = u(x[i])*v(x[i]);
		ans = ans + temp;
	}

	return ans;
}

