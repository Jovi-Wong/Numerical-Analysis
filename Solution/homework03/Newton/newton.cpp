#include "newton.h"

int NewtonFormula::f()
{
	for(int k=0; k<x_axis.size(); k++)
	{	
		double a=0;
		for(int i=0; i<=k; i++)
		{
			double q=1;
			for(int j=0; j<=k; j++)
			{
				if(j != i)
				{
					q = q*(x_axis[i]-x_axis[j]);
				}
			}
			a = a + y_axis[i]/q;
		}
		cof.push_back(a);
	}
	return 0;
}

NewtonFormula::NewtonFormula(vector<double> p1, vector<double> p2)
{
	ofstream fout("test.txt", ios::app);
	x_axis = p1;
	y_axis = p2;
	f();
	fout << "x  ";
	for (int i=0; i<x_axis.size(); i++)
	{
		fout << x_axis[i] << " ";
	}
	fout <<endl;
	fout << "y ";
	for (int i=0; i<x_axis.size(); i++)
	{
		fout << x_axis[i] << " ";
	}
	fout << endl;
};

double NewtonFormula::p(double x)
{
	ofstream fout("test.txt", ios::app);
	double ans = cof[0];
	fout << "input x = " << x << endl;
	for(int k=1; k<x_axis.size(); k++)
	{
		double mul=1;
		for(int i=0; i<=k-1; i++)
		{
			mul=mul*(x-x_axis[i]);
		}
		ans=ans+cof[k]*mul;
	}
	fout << "output y = " << ans <<endl;	
	return ans;
};
