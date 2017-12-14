#include "complex.h"
#include <iostream>
using namespace std;

float Complex::get_real_part() const { return real; }

float Complex::get_imaginary_part() const { return img; }

Complex &Complex::operator+=(Complex &c) {
  real += c.real;
  img += c.img;
  return *this;
}

Complex &Complex::operator-=(Complex &c) {
  real -= c.real;
  img -= c.img;
  return *this;
}

Complex &Complex::operator*=(Complex &c) {
  float r = (real * c.real) - (img * c.img);
  float i = (real * c.img) + (img * c.real);

  real = r;
  img = i;
  return *this;
}

Complex &Complex::operator/=(Complex &c) {
  float r = (real * c.real) + (img * c.img);
  float i = -(real * c.img) + (img * c.real);
  float d = (c.real * c.real) + (c.img * c.img);
  real = r / d;
  img = i / d;
  return *this;
}

Complex operator+(const Complex &left, const Complex &right) {
  return Complex((left.get_real_part() + right.get_real_part()),
                 (left.get_imaginary_part() + right.get_imaginary_part()));
}

Complex operator-(const Complex &left, const Complex &right) {
  return Complex((left.get_real_part() - right.get_real_part()),
                 (left.get_imaginary_part() - right.get_imaginary_part()));
}

Complex operator*(const Complex &left, const Complex &right) {
  return Complex((left.get_real_part() * right.get_real_part()) -
                     (left.get_imaginary_part() * right.get_imaginary_part()),
                 (left.get_real_part() * right.get_imaginary_part()) +
                     (left.get_imaginary_part() * right.get_real_part()));
}

Complex operator/(const Complex &left, const Complex &right) {
  double d = (right.get_real_part() * right.get_real_part()) +
             (right.get_imaginary_part() * right.get_imaginary_part());

  Complex result(((left.get_real_part() * right.get_real_part()) +
                  (left.get_imaginary_part() * right.get_imaginary_part())) /
                     d,
                 ((left.get_real_part() * right.get_imaginary_part()) +
                  (left.get_imaginary_part() * right.get_real_part())) /
                     d);

  return result;
}

ostream &operator<<(ostream &out, const Complex &c) {
  cout << c.get_real_part();

  if (c.get_imaginary_part() < 0) {
    out << "-i" << -(c.get_imaginary_part());
  } else {
    out << "+i" << c.get_imaginary_part();
  }

  return out;
}

istream &operator>>(istream &in, Complex &r) {
  float real, img;

  in >> real;

  char c;

  in >> c;

  int sign = 0;

  if (c == '-') {
    sign = 1;
  }

  in >> c;

  if (c == 'i') {
    in >> img;

    if (sign == 1)
      img = -img;
  } else {
    img = 0;
  }

  r = Complex(real, img);
  return in;
}