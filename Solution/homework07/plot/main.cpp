#include "plot.h"

int main(void)
{
	double tp=0.0;
	std::ofstream fout("data.txt", std::ios::app);
	fout <<"cond_f(x) : "<<std::endl;
	for(int i=1; i<=100; i++)
	{
		tp = 0.01 + tp;
		std::cout << tp << " ";
		fout << condf(tp) << " ";
	}
	std::cout << std::endl;
	tp = 0.0;
	fout << std::endl << std::endl<< "cond_A(x) : " << std::endl;
	for(int i=1; i<=100; i++)
	{
		tp = 0.01 + tp;
		fout << condA(tp) << " ";
	}
	return 0;
}
