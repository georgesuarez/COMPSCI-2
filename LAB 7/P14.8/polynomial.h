#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

using namespace std;

class Polynomial
{

  public:
	Polynomial(){};
	Polynomial(vector<float> c) : coeff(c) {}

	float read(int i) const;
	int size() const;
	void push(float value);

  private:
	vector<float> coeff;
};

Polynomial operator+(const Polynomial &left, const Polynomial &right);
Polynomial operator-(const Polynomial &left, const Polynomial &right);
Polynomial operator*(const Polynomial &left, const Polynomial &right);

ostream &operator<<(ostream &out, const Polynomial &p);

#endif