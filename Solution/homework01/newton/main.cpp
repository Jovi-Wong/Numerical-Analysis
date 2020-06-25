#include "newton.h"

int main()
{
	double eps;
	int M;
	NewtonMethod nt(f, df, -1);
	std::cout << "Please input epsilon value." << std::endl;
	std::cin >> eps;
	std::cout << "Please input M value." << std::endl;
	std::cin >> M;
	double x = nt.newton(M, eps);
	std::cout << "Iterating from -1, x's value is " << x  << std::endl;
	return 0;
}
