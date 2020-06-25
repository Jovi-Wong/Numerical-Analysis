#include "DLS.h"

int main()
{
	double ans = 0.0;
	/* Test func(x)
	std::cout << "func(2.0) = " << func(2.0) << std::endl;
	*/
	double Gram[3][3] =
	{
		{InnerProduct(u1,u1),InnerProduct(u1,u2),InnerProduct(u1,u3)},
		{InnerProduct(u2,u1),InnerProduct(u2,u2),InnerProduct(u2,u3)},
		{InnerProduct(u3,u1),InnerProduct(u3,u2),InnerProduct(u3,u3)}, 
	};
	/* Have a look at Gram matrix
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			std::cout << Gram[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/		
	double C[3][1]=
	{
		{InnerProduct(func,u1)},
		{InnerProduct(func,u2)},
		{InnerProduct(func,u3)}
	};
	
	lapack_int ipiv[3];
	lapack_int n=3;
	lapack_int lda=3;
	lapack_int ldb=1;
	lapack_int nrhs=1;
	lapack_int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, *Gram, lda, ipiv, *C, ldb);
	/* check info
	std::cout << info << std::endl;
	*/
	for(int i=0; i<3; i++)
	{
		std::cout << C[i][0] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
