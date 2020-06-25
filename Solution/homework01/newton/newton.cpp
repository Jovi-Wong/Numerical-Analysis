#include "newton.h"

NewtonMethod::NewtonMethod(double (*func)(double), double (*dfunc)(double), double x)
{
	f = func;
	df = dfunc;
	x0 = x;
};

double f(double x)
{
	return (4*pow(x,3)-2*pow(x,2)+3);
};

double df(double x)
{
	return (12*pow(x,2)-4*x);
};

double NewtonMethod::newton(int M, double epi)
{
	std::ofstream fout("example.txt",std::ios::app);
	fout<< "When M = " <<M<<" and epsilon = " << epi<<std::endl;
	int k;	
	double x = x0;
	double u;
	for(k=0; k<=M; k++)
	{
		u = f(x);
		if(fabs(u)<epi)
		{
			break;
		}
		x = x-(u/df(x));
		
	}
	fout << "k is " << k << std::endl;
	fout << "x is " << x << std::endl;
	std::cout << "k is " << k << std::endl;
	fout.close();
	return x;
};


