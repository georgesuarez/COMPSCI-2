#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void reverse(vector<int> &a, int i, int j)
{
	while (i < j)
	{
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

bool generate_permutations(vector<int> &a)
{
	for (int i = a.size() - 1; i > 0; i--)
	{
		if (a[i - 1] < a[i])
		{
			int j = a.size() - 1;

			while (a[i - 1] > a[i])
				j--;

			swap(a[i - 1], a[i]);
			reverse(a, i, a.size() - 1);
			return true;
		}
	}
	return false;
}

void print(const vector<int> &a, string s)
{
	for (int i = 0; i < a.size(); i++)
		cout << s[a[i]] << " ";

	cout << endl;
}

int main()
{
	string s;

	cout << "Enter word: ";
	cin >> s;

	cout << endl;

	const int n = s.length();
	vector<int> a(n);

	for (int i = 0; i < a.size(); i++)
	{
		a[i] = i;
		print(a, s);
		while (generate_permutations(a))
			print(a, s);
	}

	return 0;
}
