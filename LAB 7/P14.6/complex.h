#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex
{

  public:
	Complex() : real(0), img(0) {}
	Complex(float r) : real(r), img(0) {}
	Complex(float r, float i) : real(r), img(i) {}

	float get_real_part() const;
	float get_imaginary_part() const;

	Complex &operator+=(Complex &c);
	Complex &operator-=(Complex &c);
	Complex &operator*=(Complex &c);
	Complex &operator/=(Complex &c);

  private:
	float real;
	float img;
};

Complex operator+(const Complex &left, const Complex &right);
Complex operator-(const Complex &left, const Complex &right);
Complex operator*(const Complex &left, const Complex &right);
Complex operator/(const Complex &left, const Complex &right);

ostream &operator<<(ostream &out, const Complex &c);
istream &operator>>(istream &in, Complex &r);

#endif