#include "bisection.h"

int main()
{
	std::ofstream fout("data_plot.txt", std::ios::app);

	int Num[3] = {10,40,160};
	for(int i=0; i<3; i++)
	{
		fout << "N is " << Num[i] << std::endl;
		double interval = 2.0*sqrt(3)/Num[i];
		for(int k=0; k<=Num[i]; k++)
		{	
			double temp = interval*k-sqrt(3);
			fout << temp << " ";
		}
		fout << std::endl<<std::endl;
		
		for(int k=0; k<=Num[i]; k++)
		{	
			double temp = interval*k-sqrt(3);
			fout << func1(temp) << " ";
		}
		fout << std::endl<<std::endl;

		for(int k=0; k<=Num[i]; k++)
		{	
			double temp = interval*k-sqrt(3);
			fout << func2(temp) << " ";
		}
		fout << std::endl<<std::endl;
	}
	return 0;
}
