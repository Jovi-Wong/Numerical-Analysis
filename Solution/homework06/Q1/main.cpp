#include "compute.h"

int main(void)
{
	double tp = 0.99; /*test point*/
	double interval = 0.02/100.0;
	std::ofstream fout("data.txt",std::ios::app);
	fout << "f(x)" << std::endl;
	while (tp<=1.01)
	{
		fout << f(tp) << " ";
		tp = tp + interval;
	}
	fout << std::endl;
	tp = 0.99;
	fout << "g(x)" << std::endl;
	while(tp <= 1.01)
	{
		fout << g(tp) << " ";
		std::cout << tp << " ";
		tp = tp + interval;
	}
	fout << std::endl << "h(x)" << std::endl;
	tp = 0.99;
	while (tp <= 1.01)
	{
		fout << h(tp) << " ";
		tp = tp + interval;
	}
	return 0;
}
