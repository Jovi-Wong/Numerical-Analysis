#include "bisection.h"

int main()
{
	double eps;
	/*When f's value is close to zero enough, to be specific, f(x)<epsilon, then return x*/
	int M;
	/*Limit calculation resource, when the program circulate more than M times, then exits*/
	double delta;
	/*If the inteval is narrow than delta, then exits */

	std::cout << "please input epsilon value" << std::endl; 
	std::cin >> eps;
	std::cout << "please input delta value "<< std::endl;
	std::cin >> delta;
	std::cout << "please input M value "<< std::endl;
	std::cin >> M;

	ScalarFunc f1(func1, 0, M_PI/2);
	ScalarFunc f2(func2, 0, 1);
	ScalarFunc f3(func3, 1, 3);
	ScalarFunc f4(func4, 0, 4);

	std::cout<<"The numbers below represent c, h and k respectively."<<std::endl;
	bisect(f1, eps, delta, M);
	bisect(f2, eps, delta, M);
	bisect(f3, eps, delta, M);
	bisect(f4, eps, delta, M);	
	return 0;
}
