#include "secant.h"
double f1(double x)
{
	return (sin(x/2)-1);
};

double f2(double x)
{
	return (exp(x)-tan(x));
};

double f3(double x)
{
	return (pow(x,3)-12*pow(x,2)+3*x + 1);
};

SecantMethod::SecantMethod(double (*func)(double), double x, double y)
{
	f = func;
	x0 = x;
	x1 = y;
};
int SecantMethod::secant(int M, double delta, double eps)
{
	std::ofstream fout("example.txt", std::ios::app);
	double xn = x1;
	double xn1 = x0;
	double u = f(xn);
        double v = f(xn1);
	int k;
	double s;
	fout << "When M = "<< M <<" and delta = " << delta << " and epsilon = "<<eps<<std::endl;
	for(k=2; k<=M; k++)
	{
		if (fabs(u) > fabs(v))
		{
			std::swap(xn,xn1);
			std::swap(u,v);
		}
		s = (xn-xn1)/(u-v);
		xn1 = xn;
		v = u;
		xn = xn - u*s;
		u = f(xn);
		if( fabs(xn-xn1) < delta or fabs(u) < eps )
		{
			break;
		}	
	}	
	std::cout << xn1 << " and " << xn <<" and " << k <<std::endl; 
	fout <<"Xn1 = "<< xn1 << " and Xn = " << xn <<" and k = " << k <<std::endl; 
	return 0;
};

