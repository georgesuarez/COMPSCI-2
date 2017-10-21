/*
	Modify the class Fraction to permit fractions with a zero denominator.
    Change the stream output operator so that it will produce a special marker,
	*****, when such a value is printed. Modify the conversion operator double so that
	it will produce the value zero in this case. Finally, add a conversion operator bool so
	as to test whether a Fraction is proper.
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main() {

	Fraction a(-4, 2);

	Fraction b(4);

	Fraction c(0, 0);

	cout << "Constructed values a = " << a << " b = " << b << " c = " << c << endl << endl;

	if ((bool)a)
	{
		cout << a << " is a proper fraction." << endl << endl;
	}
	else
	{
		cout << a << " is not a proper fraction." << endl << endl;
	}

	cout << "one-third of " << b << " is " << (double)b / 3 << endl << endl;


	return 0;
}