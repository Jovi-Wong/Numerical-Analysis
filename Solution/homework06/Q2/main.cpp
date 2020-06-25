#include <iostream>
#include <cmath>

double d2b(double x)
{
	double num = 0.0;
	double c = 0.0;
	while (x != 0)
	{
		if (x >= 1)
		{
			x = (x-1)*2.0;
			num = num + pow(10,-c);
			c = c + 1.0;
		}
		else
		{
			x = x*2.0;
			c = c + 1.0;
		}
	}
	return num;
}

int main(void)
{
	double beta = 2.0;
	double p = 3.0;
        double L = -1.0;
 	double U = 1.0;
	double e = L;
	double UFL = pow(beta,L);
	double OFL = pow(beta,U)*(beta-pow(beta,1-p));
	std::cout << "UFL(F) = " << UFL << std::endl;
	std::cout << "OFL(F) = " << OFL << std::endl;
	double eps = pow(beta,1-p);
	std::cout << "Enumerate normalized FPN" << std::endl;
	while (e <= U)
	{
		double p = 1.0;
		for(int i=0; i<4; i++)
		{
			std::cout << pow(10,e)*d2b(p) << " , ";
			p = p + eps;
		}
		std::cout << std::endl;
 		e = e + 1.0;
	}
	
	e = L; 
	while (e <= U)
	{
		double p = 1.0;
		for(int i=0; i<4; i++)
		{
			std::cout <<"-" << d2b(p)*pow(10,e) << " , ";
			p = p + eps;
		}
		std::cout << std::endl;
 		e = e + 1.0;
	}

	e=L;
	while (e <= U)
	{
		double p = 1.0;
		for(int i=0; i<4; i++)
		{
			std::cout << d2b(p) << "*2^{"<< e <<"}" << " , ";
			p = p + eps;
		}
		std::cout << std::endl;
 		e = e + 1.0;
	}	
	
	e=L;
	while (e <= U)
	{
		double p = 1.0;
		for(int i=0; i<4; i++)
		{
			std::cout <<"-"<< d2b(p) << "*2^{"<< e <<"}" << " , ";
			p = p + eps;
		}
		std::cout << std::endl;
 		e = e + 1.0;
	}	

	std::cout << "subnormalized numbers" << std::endl;
	e = L;
	eps = 0.125;
	for(int i=0; i<4; i++)
	{
		std::cout << (eps*i) << " ";
	}
	std::cout << std::endl;
	for(int i=0; i<4; i++)
	{
		std::cout << (-eps*i) << " ";
	
	}
	std::cout << std::endl;
	return 0;
}
