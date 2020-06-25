#include "PLG.h"

Lattice::Lattice(string filename)
{
	vector<double> pos;
	ifstream fin("./test_data/"+filename);
	fin >> D >> N;
	
	int input;
	while(fin >> input)
	{
		pos.push_back(input);
	}
	POS = pos;

	double total = pow(N,D);
	for(int i=0; i<total; i++)
	{
		int cord[D];
		double num = i;
		int sum = 0;
		
		for(int j=0; j<D; j++)
		{
			int slice = floor(num/pow(N,D-j-1));
			num = num-pow(N,D-j-1)*slice;
			cord[j]= slice;
			sum = sum + slice;
		}

		if(sum < N)
		{
			vector<double> a;
			vector<int> b;
			for(int i=0; i<D; i++)
			{
				a.push_back(pos[cord[i]]);
				b.push_back(cord[i]);
			}
			point.push_back(a);
			permutation.push_back(b);
		}	
	}
	display("./result/result_"+filename);
}

Lattice::Lattice(int d, int n, vector<double> pos)
{
	D = d;
	N = n;
	int total = pow(n,d);
	POS = pos;	
	for(int i=0; i<total; i++)
	{
		int cord[D];
		double num = i;
		int sum = 0;
		
		for(int j=0; j<D; j++)
		{
			int slice = floor(num/pow(n,D-j-1));
			num = num-pow(n,D-j-1)*slice;
			cord[j]= slice;
			sum = sum + slice;
		}

		if(sum < n)
		{
			vector<double> a;
			vector<int> b;
			for(int i=0; i<D; i++)
			{
				a.push_back(pos[cord[i]]);
				b.push_back(cord[i]);
			}
			point.push_back(a);
			permutation.push_back(b);
		}	
	}
}

int test(string filename)
{
	vector<double> pos;
	int dim;
	int num;
	ifstream fin("./test_data/"+filename);
	fin >> dim >> num;
	int input;
	while(fin >> input)
	{
		pos.push_back(input);
	}
	Lattice A(dim,num,pos);
	A.display("./result/result_"+filename);
	return 0;
}

int Lattice::display(string filename)
{
	ofstream fout("./result/"+filename);
	for(auto iter=point.begin(); iter != point.end(); iter++)
	{
		for(int i=0; i<D; i++)
		{
			fout << (*iter)[i] << " ";
		}
		fout << endl;
	}
	return 0;
}

vector<double> u1(double x, double y)
{
	vector<double> rst;
	double p1 = pow(sin(pi*x),2)*sin(2*pi*y);
	double p2 = -sin(2*pi*x)*pow(sin(pi*y),2);
	rst.push_back(p1);
	rst.push_back(p2);
	return rst;
}

vector<double> u2(double x, double y, double z)
{
	vector<double> rst;
	double p1 = pow(sin(pi*x),2)*sin(2*pi*y)*sin(2*pi*z);
	double p2 = sin(2*pi*x)*pow(sin(pi*y),2)*sin(2*pi*z);
	double p3 = -2*sin(2*pi*x)*sin(2*pi*y)*pow(sin(pi*z),2);
	rst.push_back(p1);
	rst.push_back(p2);
	rst.push_back(p3);	
	return rst;
}

double Lattice::nodef(int index, double x)
{
	if(index == 0)
	{
		return 1.0;
	}
	else
	{
		double prod = 1.0;
		for(int i=0; i<index; i++)
		{
			prod = prod*(x-POS[i]);
		}
		return prod;
	}
}

double Lattice::p(int m, double x, double y, int fenliang)
{
	if(m == 0)
	{
		return (u1(x,y)[fenliang]);
	}
	else
	{
		return (p(m-1,x,y,fenliang)+q(m,x,y,fenliang));
	}
	
}

double Lattice::q(int m, double x, double y, int fenliang)
{
	double sum=0;
	for(int k=0; k<=m; k++)
	{
		vector<double> v1;
		vector<double> v2;
		for(int i=0; i<=k; i++)
		{
			v1.push_back(POS[i]);
		}
		for(int i=0; i<=(m-k); i++)
		{
			v2.push_back(POS[i]);
		}
		int tt = v1.size();
		double temp1 = nodef(k,x);
		double temp2 = nodef(m-k,y);
		double temp3 = divdiff(fenliang, v1, v2);
		sum = sum + temp1*temp2*temp3;
	}
	return sum;
}

double Lattice::divdiff(int fenliang, vector<double>& v1, vector<double>& v2)
{
	if ((v1.size() == 1) and (v2.size()==1))
	{
		return u1(v1[0],v2[0])[fenliang];
	}
	else
	{
		if(v1.size()==1)
		{
			double xk = v2[v2.size()-1];
			double x0 = v2[0];
			vector<double> v21(v2.begin()+1,v2.end());
			vector<double> v22(v2.begin(),v2.end()-1);
			double temp1=divdiff(fenliang,v1,v21);
			double temp2=divdiff(fenliang,v1,v22);
			return ((temp1-temp2)/(xk-x0));
		}
		else
		{
			double xk = v1[v1.size()-1];
			double x0 = v1[0];
			vector<double> v11(v1.begin()+1,v1.end());
			vector<double> v12(v1.begin(),v1.end()-1);
			double temp1 = divdiff(fenliang,v11,v2);
			double temp2 = divdiff(fenliang,v12,v2);	
			return ((temp1-temp2)/(xk-x0));
		}
	}	
}

vector<double> Lattice::poly(double x, double y)
{
	vector<double> rst;
	for(int i=0; i<2; i++)
	{
		double temp = p(N,x,y,i);
		rst.push_back(temp);
	}
	return rst;	
}
