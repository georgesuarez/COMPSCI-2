/*
	Write a function that removes duplicates from a vector. For example,
	if remove_duplicates is called with a vector containing

				 1 4 9 16 9 7 4 9 11

	After removing duplicates 
	
				  1 4 9 16 7 11
*/

#include <iostream>
#include <vector>

using namespace std;

void remove_duplicates(vector<int> &a)
{
	int n = a.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n;)
		{
			if (a[i] == a[j])
			{
				for (int k = j; k < n - 1; k++)
				{
					a[k] = a[k + 1];
				}
				a.pop_back();
				n--;
			}
			else
				j++;
		}
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

	vector<int> numbers{1, 4, 9, 16, 9, 7, 4, 9, 11};

	cout << "Before removing duplicates: ";
	print(numbers);

	cout << endl
		 << endl;

	remove_duplicates(numbers);

	cout << "After removing duplicates: ";
	print(numbers);

	cout << endl
		 << endl;

	return 0;
}