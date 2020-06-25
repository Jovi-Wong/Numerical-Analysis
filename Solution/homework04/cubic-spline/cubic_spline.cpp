#include "cubic_spline.h"

double f(double x)
{
	return (1.0/(1.0+25.0*x*x));
};

int cubic_spline(int N, double(*func)(double))
{
	double A[N-2][N-2];
	double interval = 2.0/(N-1);
	for(int row=0; row<N-2; row++)
	{
		for(int col=0; col<N-2; col++)
		{
			if (col==row)
			{
				A[row][col]=2.0;
			}
			else 
			{
				if ((col == row-1) or (col == row+1))
				{
					A[row][col]=0.5;
				}
				A[row][col] = 0.0;
			}
		}
	}

	double xn[N];
	for(int i=0; i<N; i++)
	{
			xn[i]=i*2.0/(N-1)-1.0;
	}

	double B[N-2][1];
	for(int i=0; i<N-2; i++)
	{
		if(i==0)
		{
			B[i][0]=1.5*(func(xn[i+2])-func(xn[i]))/interval-25.0/676.0;
		}
		else
		{
			if(i==N-3)
			{
				B[i][0]=1.5*(func(xn[i+2])-func(xn[i]))/interval+25.0/676.0;
			}
			B[i][0]=1.5*(func(xn[i+2])-func(xn[i]))/interval;
		}
	}

	lapack_int ipiv[N-2];
	lapack_int n=N-2;
	lapack_int lda=N-2;
	lapack_int ldb=1;
	lapack_int nrhs=1;
	lapack_int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, *A, lda, ipiv, *B, ldb);
	
	double K[N-1];
	for(int i=0; i<N-1; i++)
	{
		K[i] = (func(xn[i+1])-func(xn[i]))/interval;
	}
	
	double f[N];
	double c0[N];
	for(int i=0; i<N; i++)
	{
		f[i] = func(xn[i]);
	        c0[i] = f[i];	
	}

	double m[N];
	double c1[N];
	for(int i=0; i<N; i++)
	{
		if (i==0)
		{
			m[i]= 50.0/676.0;
			c1[i] = m[i];
		}
		else
		{
			if(i==N-1)
			{
				m[i]= -50.0/676.0;
				c1[i]=m[i];
			}
			m[i] = B[i-1][0];
			c1[i] = m[i];
		}
	}
	
	double c2[N-1];
	for(int i=0; i<N-1; i++)
	{
		c2[i]=(3.0*K[i]-2.0*m[i]-m[i+1])/interval;
	}

	double c3[N-1];
	for(int i=0; i<N-1; i++)
	{
		c3[i]= (m[i]+m[i+1]-2.0*K[i])/(interval*interval);
	}

	std::ofstream fout("test.txt", std::ios::app);
	fout << "The values of each point" << std::endl;
	fout << "N = " << N << std::endl;
	for(int i=0; i<N-1; i++)
	{
		for (int k=0; k<10; k++)
		{
			double x= xn[i]+ interval/10*k;
			fout << c0[i]+c1[i]*(x-xn[i])+c2[i]*pow(x-xn[i],2)+c3[i]*pow(x-xn[i],3) << " ";
		}
	}
	fout << std::endl << std::endl;
	
	fout<< "The errors of each points" << std::endl;
	fout << "N = " << N << std::endl;
	for(int i=0; i<N-1; i++)
	{
		for (int k=0; k<10; k++)
		{
			double x= xn[i]+ interval/10*k;
			fout << abs(c0[i]+c1[i]*(x-xn[i])+c2[i]*pow(x-xn[i],2)+c3[i]*pow(x-xn[i],3)-1.0/(1.0+25*x*x)) << " ";
		}
	}
	fout << std::endl << std::endl;


	return info;
};


