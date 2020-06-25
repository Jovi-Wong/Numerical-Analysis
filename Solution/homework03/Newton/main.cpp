#include "newton.h"

int main()
{
	ofstream fout("plot_data.txt",ios::app);
	double num[4] = {2,4,6,8};
	for(int n=0; n<4; n++)
	{
		vector<double> xi;
		vector<double> fi;
		for(int i=0; i<=num[n]; i++)
		{
			double x = -5 + (10*i)/num[n];
			xi.push_back(x);
			fi.push_back(1/(1+x*x));
			cout << " " << (x) << " ";
		}
		double x;
		NewtonFormula A(xi,fi);
		fout << "Now n = " << num[n] << endl;
		fout << "[";
		for(double x=-5; x<=5; x=x+0.1)
		{
			fout<<A.p(x)<< " ";
		}
		fout<< "]"<< endl << endl;
	}
	return 0;
}
