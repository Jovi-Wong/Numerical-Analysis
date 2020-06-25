#include "cardinal.h"

double B2(int i, double x)
{
	double di = (double) i;
	if(((di-1)<x) and (x<=di))
	{
		return ((x-di+1)*(x-di+1)/2.0);
	}
	else
	{
		if((di<x) and (x<= di+1))
		{
			return(3.0/4.0-(x-di-0.5)*(x-di-0.5));
		}
		else
		{
			if((di+1<x) and (x<di+2))
			{
				return((di+2-x)*(di+2-x)/2.0);
			}
			else
			{
				return 0.0;
			}
		}
	}
}

double B3(int i, double x)
{
	double di = (double) i;
	if(((di-1)<x) and (x<=di))
	{
		return ((x-di+1)*(x-di+1)*(x-di+1)/6.0);
	}
	else
	{	
		if((di<x) and (x<=di+1))
		{	
			return (2.0/3.0-(x-di+1)*(di+1-x)*(di+1-x)/2.0);
		}
		else
		{
			if((di+1<x) and (x<di+3))
			{
				return (B3(i,2*di+2-x));
			}
			else
			{	
				return (0.0);
			}
		}

	}
}

quadratic_cardinal::quadratic_cardinal(int n, double(*f)(double))
{
	func = f;
	N = n;
	a = new double[N];
	double M[N-1][N-1];
	/*initialize matrix M*/
	for(int row=0; row<N-1; row++)
	{
		for(int col=0; col<N-1; col++)
		{
			if (col==row)
			{
				M[row][col]=6.0;
			}
			else 
			{
				if ((col == row-1) or (col == row+1))
				{
					M[row][col] = 1.0;
				}
				else
				{
					M[row][col] = 0.0;
				}
			}
			/* for test
			std::cout << M[row][col] << " ";
			*/
		}
		/*
		std::cout << std::endl;
		*/
	}
	M[0][0] = M[N-1][N-1] = 5.0;
	
	double t[N];
	/*store intepolating points t_i*/
	for(int i=1; i < N; i++)
	{
		t[i]=i-5.5;
	}

	double b[N-1][1];
	/*initialize b as Corollary 4.43*/
	for(int i=0; i<N-1; i++)
	{
		if(i==0)
		{
			b[i][0]=8.0*func(t[i+1])-2.0*func(-5.0);
			/* for test
			std::cout << "b[" << i<<"] = " << b[i][0] << std::endl;
			*/
		}
		else
		{
			if(i==(N-2))
			{
				b[i][0]=8.0*func(t[i+1])-2.0*func(5.0);
				/* for test
				std::cout << "b[" << i<<"] = " << b[i][0] << std::endl;
				*/
			}
			else
			{
				b[i][0]=8.0*func(t[i+1]);
				/*	for test
				std::cout << "b[" << i<<"] = " << b[i][0] << std::endl;
				*/
			}
		}
	}

	lapack_int ipiv[N-1];
	lapack_int num=N-1;
	lapack_int lda=N-1;
	lapack_int ldb=1;
	lapack_int nrhs=1;
	lapack_int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, num, nrhs, *M, lda, ipiv, *b, ldb);
	
	for(int i=1; i<N; i++)
	{
		a[i]=b[i-1][0];
		/* for test
		std::cout << a[i] << " ";
		*/
	}
	/*
	std::cout <<std::endl << "info = " << info << std::endl;
	*/
}

double quadratic_cardinal::S(double x)
{
	double a0 = 2.0*func(-5.0)-a[1];
	double aN = 2.0*func(5.0)-a[N-1];
	double sx = a0*B2(-6,x)+aN*B2(5,x);
	for(int i=1; i<N+1; i++)
	{
/*		for test
 *		std::cout <<"B2(" << (i-6)<<","<<x<<") = "<<B2(i-6,x) << std::endl;
 */		
		sx = sx + a[i]*B2(i-6,x);
	}
	return sx;
}

void quadratic_cardinal::plot(void)
{
	std::ofstream fout("quacard_data.txt",std::ios::app);
	double interval = 0.1;
	double x;
	for(int i=0; i<101; i++)
	{
		x=-5.0+i*interval;
		fout << x << " ";
	}

	fout << std::endl << std::endl;
	
	for(int i=0; i<101; i++)
	{
		x=-5.0+i*interval;
		fout << S(x) << " ";
	}
	
	fout << std::endl <<std::endl;
}

cubic_cardinal::cubic_cardinal(int n, double(*f)(double), double d1, double dN)
{
	df1 = d1;
	dfN = dN;
	func = f;
	N = n;
	a = new double[N];

	double M[N][N];
	/*initialize matrix M*/
	for(int row=0; row<N; row++)
	{
		for(int col=0; col<N; col++)
		{
			if (col==row)
			{
				M[row][col]=4.0;
			}
			else 
			{
				if((col == row-1) or (col == row+1))
				{
					M[row][col]=1.0;
				}
				else
				{
					M[row][col] = 0.0;
				}
			}
		}
	}
	M[0][1] = M[N-1][N-2] = 2.0;

	double t[N];
	/*store interpolating points*/
	for(int i=1; i<=N; i++)
	{
		t[i-1]=-6.0+i;
	}

	double b[N][1];
	/*initialize b as Corollary 4.43*/
	for(int i=0; i<N; i++)
	{
		if(i==0)
		{
			b[i][0]=6.0*func(t[i])+2.0*df1;
		}
		else
		{
			if(i==(N-1))
			{
				b[i][0]=6.0*func(t[i])-2.0*dfN;
			}
			else
			{
				b[i][0]=6.0*func(t[i]);
			}
		}
	}

	lapack_int ipiv[N];
	lapack_int num=N;
	lapack_int lda=N;
	lapack_int ldb=1;
	lapack_int nrhs=1;
	lapack_int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, num, nrhs, *M, lda, ipiv, *b, ldb);
	
	for(int i=0; i<N; i++)
	{
		a[i]=b[i][0];
		/*  for test
		std::cout << "a[" << i<<"] = "<<a[i]<< std::endl;
		*/
	}
	/*
	std::cout << "info = " << info << std::endl;
	*/
};

double cubic_cardinal::S(double x)
{
	double a_1 = a[1]-2.0*df1;
	double aN = a[N-2]+2.0*dfN;
	double sx = a_1*B3(-7,x) + aN*B3(5,x);
	for(int i=0; i<N; i++)
	{
		/* for test
		std::cout<< "B3(" << i-6 << "," << x<<") = "<< B3(i-6,x)<< std::endl;
		*/
		sx = sx + a[i]*B3(i-6,x);
	}
	return sx;
}


void cubic_cardinal::plot(void)
{
	std::ofstream fout("cubcard_data.txt",std::ios::app);;
	double interval = 0.1;
	double x;
	for(int i=0; i<101; i++)
	{
		x=-5+i*interval;
		fout << x << " ";
	}
	fout << std::endl << std::endl;
	for(int i=0; i<101; i++)
	{
		x=-5+i*interval;
		fout << S(x) << " ";
	}
	fout << std::endl <<std::endl;
}



double function(double x)
{
	return (1.0/(1+x*x));
}
