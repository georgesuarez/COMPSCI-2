#include <iostream>
#include <vector>
#include "polynomial.h"
using namespace std;

int main() {

	vector<float> acoeff(3);

	acoeff[0] = 2;
	acoeff[2] = 1;

	vector<float> bcoeff(2);
	
	bcoeff[1] = 4;
	bcoeff[0] = 2;

	Polynomial a(acoeff);
	Polynomial b(bcoeff);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl << endl;

	return 0;
}