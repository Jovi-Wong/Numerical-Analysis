#include "QR.h"

static double x[21] = {0.0,0.5,1.0,1.5,2.0,2.5,3.0,
		3.5,4.0,4.5,5.0,5.5,6.0,6.5,
		7.0,7.5,8.0,8.5,9.0,9.5,10.0};

static double y[21] = {2.9,2.7,4.8,5.3,7.1,7.6,7.7,  		
		7.6,9.4,9.0,9.6,10.0,10.2,9.7,
		8.3,8.4,9.0,8.3,6.6,6.7,4.1}; 		
	
int main(void)
{
	/*Firstly, get the degree of fitting polynomial*/
	int degree = 0;
	std::cout << "Please input the maximum degree of fitting polynomial" << std::endl;
	std::cin >> degree;
	degree = degree +1;
	/*Secondly, initialize the matrix A and b*/
	double a[21*degree];
	for(int row=0; row<21; row++)
	{
		for(int col=0; col<degree; col++)
		{
			a[row*degree+col]=u(col,x[row*degree]);
		}
	}
	double* A = a;
	
	double b[21];
	for(int row=0; row<21; row++)
	{
		b[row]=y[row];
	}
	double* B = b;
	/*Thirdly, decompose A into QR*/
	
	double q[21*21];
	double r[21*degree];
	double* Q = q;
	double* R = r;
	for(int i=0; i<21*21; i++)
	{
		q[i]=0;
	}

	for(int i=0; i<21*degree; i++)
	{
		r[i]=0;
	}
	
	int tmp = qr(Q, R, A, 21, degree);
	
	/*Fourthly, obtain R1 from R and c from Q^Tb*/
	double r1[degree][degree];
	std::cout << "matrix R1" <<std::endl;	
	for(int row=0; row<degree; row++)
	{
		for(int col=0; col<degree; col++)
		{		
			r1[row][col] = R[row*degree+col];
			std::cout << r1[row][col]<< " ";
		}
		std::cout << std::endl;
	}

	double qt[21*21];
	double* QT = qt;
	trans(Q, 21, 21, QT);
	double c[degree][0];
	
	std::cout << "matrix c" <<std::endl;
	for(int row=0; row<degree; row++)
	{
		double temp = 0.0;
		for(int col=0; col<21; col++)
		{
			temp = temp + qt[row*21+col]*b[col];
		}
		c[row][0] = temp;
		std::cout << c[row][0] << " ";
	}
	std::cout << std::endl;

	/*Fifthly, solve R1x=c to get the coefficients*/
	
	lapack_int ipiv[degree];
	lapack_int n = degree;
	lapack_int lda = degree;
	lapack_int ldb = 1;
	lapack_int nrhs = 1;
	lapack_int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, *r1, lda, ipiv, *c, ldb);
	
	std::cout << "Now, we get the coefficients" << std::endl;
	for(int i=0; i<degree; i++)
	{
		std::cout << c[i][0] << " ";
	}
	std::cout << std::endl;

	return 0;
}
