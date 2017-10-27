#include "polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

int Polynomial::size() const
{
	return coeff.size();
}

void Polynomial::push(float value)
{
	coeff.push_back(value);
}

float Polynomial::read(int i) const
{
	return coeff[i];
}

Polynomial operator+(const Polynomial &left, const Polynomial &right)
{
	Polynomial p, extra;

	int s1 = left.size();
	int s2 = right.size();

	int limit1, limit2;

	if (s1 < s2)
	{
		limit1 = s1;
		limit2 = s2;
		extra = right;
	}
	else
	{
		limit1 = s2;
		limit2 = s1;
		extra = left;
	}

	for (int i = 0; i < limit1; i++)
		p.push(left.read(i) + right.read(i));

	for (int i = limit1; i < limit2; i++)
		p.push(extra.read(i));

	return p;
}

Polynomial operator-(const Polynomial &left, const Polynomial &right)
{
	Polynomial p, extra;

	int s1 = left.size();
	int s2 = right.size();

	int limit1, limit2;

	if (s1 < s2)
	{
		limit1 = s1;
		limit2 = s2;
		extra = right;
	}
	else
	{
		limit1 = s2;
		limit2 = s1;
		extra = left;
	}

	for (int i = 0; i < limit1; i++)
		p.push(left.read(i) - right.read(i));

	for (int i = limit1; i < limit2; i++)
		if (limit1 == s1)
			p.push(-extra.read(i));
		else
			p.push(extra.read(i));

	return p;
}

Polynomial operator*(const Polynomial &left, const Polynomial &right)
{
	vector<float> temp(left.size() + right.size() - 1);

	for (int i = 0; i < (int)temp.size(); i++)
		temp[i] = 0;

	for (int i = 0; i < left.size(); i++)
	{
		for (int j = 0; j < right.size(); j++)
		{
			temp[i + j] += left.read(i) * right.read(j);
		}
	}

	return Polynomial(temp);
}

ostream &operator<<(ostream &out, const Polynomial &p)
{
	for (int i = p.size() - 1; i >= 0; i--)
	{
		float value = p.read(i);

		if (value != 0)
		{
			if (i < p.size() - 1)
			{
				if (value > 0)
					out << " + ";
				else
					out << " - ";
			}
			if (value > 0)
				out << value << "x^" << i;
			else
				out << -value << "x^" << i;
		}
	}

	return out;
}