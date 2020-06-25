#include "cubic_spline.h"

int main()
{
	int N[5] = {6,11,21,41,81};
	for(int i=0; i<5; i++)
	{
		std::cout << cubic_spline(N[i],f) << std::endl;
	}
	return 0;
}
