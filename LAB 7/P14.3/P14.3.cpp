/*
	Determine which functions in class Fraction are candidates for inlining.
	Rewrite the class to inline those you identify, and test the resulting application.
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{

	Fraction a;
	Fraction b(4);
	Fraction c(6, 8);

	cout << "Constructed values " << a << " " << b << " " << c << endl
		 << endl;
	cout << "Value of c is: " << c.numerator() << "/" << c.denominator() << endl
		 << endl;

	Fraction d = b + c;

	cout << "4 + 3/4 is " << d << endl
		 << endl;

	d = b - c;

	cout << "4 - 3/4 is " << d << endl
		 << endl;

	Fraction e = (b + (-c));

	cout << e << " done with negation." << endl
		 << endl;

	if (d == e)
	{
		cout << "Subtraction test successful." << endl
			 << endl;
	}

	a = Fraction(6, 8);
	b = Fraction(7, 8);

	if (a < b)
	{
		cout << "Compare successful." << endl
			 << endl;
	}

	c -= 2;

	cout << "c -= 2 is " << c << endl
		 << endl;

	b--;

	cout << "Post decremented value of b is " << b << endl
		 << endl;

	return 0;
}