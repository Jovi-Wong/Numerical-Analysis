#ifndef _JOVI_WONG_
#define _JOVI_WONG_
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#define pi 3.1415926
using namespace std;

class NewtonFormula
{
private:
	vector<double> cof;
	int f();
public:
	NewtonFormula(vector<double> p1, vector<double> p2);
	vector<double> x_axis;
	vector<double> y_axis;
	double p(double x);
};

#endif
