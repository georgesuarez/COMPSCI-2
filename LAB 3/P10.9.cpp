#include <iostream>

using namespace std;

double poly(double x[], double y[], int i, double area)
{
	if(i == 4)
	{
		return area;
	}
	else
	{
		area = area + (x[0] * y[i+1] + x[i+1] * y[i+2] + x[i+2] * y[0] - y[i+1] * x[i+2] - y[i+2] * x[0]) / 2;
		return poly(x, y, i+1, area);
	}
}

int main()
{
	double area = 0.0;
	int i = 0;

	double a[6] = {56.3, 66.4, 45.7, 35.4, 47.8, 66.7};
	double b[6] = {35.2, 67.3, 67.8, 45.6, 23.1, 25.5};
	
	area = poly(a, b, i, area);
	cout << area << endl << endl;

	return 0;
}
