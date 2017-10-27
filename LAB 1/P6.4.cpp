/*
	Write a function
	vector<int> append(vector<int> a, vector<int> b)
	that appends one vector after another. 
	
	For example,

		Vector a has: 1 4 9 16
		Vector b has: 9 7 4 9 11

		After appending: 1 4 9 16 9 7 4 9 11
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> append(vector<int> &a, vector<int> &b)
{
	int sizeOfA = a.size();
	int sizeOfB = b.size();
	vector<int> result(sizeOfA + sizeOfB);

	int index = 0;
	int i = 0;
	int j = sizeOfA;
	int k = sizeOfB;

	if (sizeOfA < sizeOfB)
	{
		while (i < sizeOfA)
		{
			result[index] = a[i];
			i++;
			index++;
		}

		i = 0;

		while (i < sizeOfB)
		{
			result[j] = b[i];
			j++;
			i++;
		}

		return result;
	}
	else
	{
		while (i < sizeOfB)
		{
			result[index] = b[i];
			i++;
			index++;
		}

		i = 0;

		while (i < sizeOfA)
		{
			result[k] = a[i];
			k++;
			i++;
		}

		return result;
	}
}

void print(vector<int> &a)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{

	vector<int> a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(9);
	a.push_back(16);

	vector<int> b;
	b.push_back(9);
	b.push_back(7);
	b.push_back(4);
	b.push_back(9);
	b.push_back(11);

	vector<int> combined = append(a, b);

	cout << "Vector a: ";
	print(a);

	cout << endl
		 << endl;

	cout << "Vector b: ";
	print(b);

	cout << endl
		 << endl;

	vector<int> result = append(a, b);

	cout << "After appending: ";
	print(result);

	cout << endl
		 << endl;

	return 0;
}