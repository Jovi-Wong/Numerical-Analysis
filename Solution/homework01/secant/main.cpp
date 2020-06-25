#include "secant.h"

int main()
{
	double eps;
	double delta;
	int M;
	SecantMethod s1(f1, 0, M_PI/2);
	SecantMethod s2(f2, 1, 1.4);
	SecantMethod s3(f3, 0, -0.5);
	std::cout << "please input epsilon value" << std::endl; 
	std::cin >> eps;
	std::cout << "please input delta value "<< std::endl;
	std::cin >> delta;
	std::cout << "please input M value "<< std::endl;
	std::cin >> M;
	std::cout <<"The numbers below are Xn, Xn-1 and k."<< std::endl;
	s1.secant(M, delta, eps);
	s2.secant(M, delta, eps);
	s3.secant(M, delta, eps);
	return 0;
}
