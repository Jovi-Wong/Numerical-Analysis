#include "QR.h"

double u(int n, double x)
{
	return pow(x,n);
}

int trans(double* A, int m, int n, double* AT)
{
	for(int row=0; row < m; row++)
	{
		for(int col=0; col<n; col++)
		{
			AT[row*n+col]=A[col*m+row];
		}
	}
}

int qr(double* const _Q, double* const _R, double* const _A, int _m, int _n) 
{
    const int rank = std::min(_m, _n); 
    const std::unique_ptr<double[]> tau(new double[rank]);
    LAPACKE_dgeqrf(LAPACK_ROW_MAJOR, (int) _m, (int) _n, _A, (int) _n, tau.get());

    for(int row =0; row < rank; row++) 
   {
	 memcpy(_R+row*_n+row, _A+row*_n+row, (_n-row)*sizeof(double));   
   }

    LAPACKE_dorgqr(LAPACK_ROW_MAJOR, (int) _m, (int) rank, (int) rank, _A, (int) _n, tau.get());

    if(_m == _n) 
    {
        memcpy(_Q, _A, sizeof(double)*(_m*_n));
    } 
    else 
    {
        for(size_t row =0; row < _m; row++) 
	{
            memcpy(_Q+row*rank, _A+row*_n, sizeof(double)*(rank));
        }
    }
    return 0;
}
