#include "cardinal.h"

int main()
{
	cubic_cardinal A(11, function, 10.0/676.0, -10.0/676.0);
	quadratic_cardinal B(11, function);
	B.plot();
	A.plot();
	return 0;
}
