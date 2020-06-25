#include "newton.h"

int main()
{
	ofstream fout("plot_data.txt",ios::app);
	double num[4] = {5,10,15,20};
	for(int n=0; n<4; n++)
	{
		vector<double> xi;
		vector<double> fi;
		for(int i=1; i<=num[n]; i++)
		{
			double x = cos((2*i-1)/(2*num[n])*pi);
			xi.push_back(x);
			fi.push_back(1/(1+25*x*x));
			cout << " " << (x)<<", " << (1/(1+25*x*x))<< " ";
		}
		cout << endl;
		double x;
		NewtonFormula A(xi,fi);
		fout << "Now n = " << num[n] << endl;
		fout << "[";
		for(double x=-1; x<=1; x=x+0.02)
		{
			fout<<A.p(x)<< " ";
		}
		fout<<A.p(1)<< "]"<< endl << endl;
	}
	return 0;
}
