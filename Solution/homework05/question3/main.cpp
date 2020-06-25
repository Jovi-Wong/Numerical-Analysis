#include "cardinal.h"

int main()
{
	cubic_cardinal A(11, function, 10.0/676.0, -10.0/676.0);
	quadratic_cardinal B(11, function);
/*	B.plot();*/
/*	A.plot();*/
	std::ofstream fout("error.txt");
	double p[7] = {-3.5,-3.0,-0.5,0.0,0.5,3.0,3.5};
	double error_A[7];
	double error_B[7];
	for(int i=0; i<7; i++)
	{
		error_A[i] = fabs(A.S(p[i])-function(p[i]));
		error_B[i] = fabs(B.S(p[i])-function(p[i]));
	}
	fout << "the error of cubic is " << std::endl;
	for(int i=0; i<7; i++)
	{
		fout << error_A[i] <<" ";
	}
	fout << std::endl;

	fout << "the error of quadratic is " <<std::endl;
	for(int i=0; i<7; i++)
	{
		fout << error_B[i] <<" ";

	}
	fout << std::endl;
	return 0;
}


