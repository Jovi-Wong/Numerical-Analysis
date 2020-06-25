#include "bisection.h"

ScalarFunc::ScalarFunc(double (*func)(double), double x, double y)
{
	f = func;
	a = x;
	b = y;
};

double func1(double x)
{
	return (1/x - tan(x));
};

double func2(double x)
{
	return (pow(x,-1)-pow(2,x));
};

double func3(double x)
{
	return (pow(2,-x)+exp(x)+2*cos(x)-6);
};

double func4(double x)
{
	return ((pow(x,3)+4*pow(x,2)+3*x+5)/(2*pow(x,3)-9*pow(x,2)+18*x-2));
};

void bisect(ScalarFunc& f1, double eps, double delta, int M)
{
	std::ofstream fout("example.txt", std::ios::app);
	double h;
	double u;
	double v;
	double c;
	double w;
	int k;
	fout << "Input function " << std::endl;
	fout<< "When epsilon = " << eps << " and delta = " << delta << " and M = " << M << std::endl; 
	u=f1.f(f1.a);
	v=f1.f(f1.b);
	for(k=1; k<=M; k++)
	{
		h=f1.b-f1.a;
		c=f1.a+h/2;
		w=f1.f(c);
		if (h<delta or fabs(w)<eps)
		{
			break;
		}
		else
		{
			if(w*u<0)
			{
				f1.b = c;
				v = w;
			}
			else
			{
				f1.a = c;
				u = w;
			}
		}
	}
	fout << c << " and " << h << " and " << k << std::endl;
	std::cout << c << " and " << h << " and " << k << std::endl;
};
