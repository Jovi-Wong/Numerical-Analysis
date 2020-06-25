#include "PLG.h"

int main()
{
	string filename = "2d.txt";
	Lattice A(filename);
	vector<double> v1, v2;
	v1.push_back(1.0);
	v2.push_back(1.0);
	v2.push_back(2.0);
	A.divdiff(0, v1, v2);	
	return 0;
}
