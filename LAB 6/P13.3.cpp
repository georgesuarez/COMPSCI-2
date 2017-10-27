/*
	Implement the sieve of Eratosthenes: a function for computing prime
	numbers, known to the ancient Greeks. Choose an integer n. This function will
	compute all prime numbers up to n. First insert all numbers from 1 to n into a set.
	Then erase all multiples of 2 (except 2); that is, 4, 6, 8, 10, 12, �. Erase all multiples
	of 3, that is, 6, 9, 12, 15, � . Go up to . The remaining numbers are all primes.
*/
#include <iostream>
#include <set>
using namespace std;

set<int> runEratosthenesSieve(int upperBound)
{
	int upperBoundSquareRoot = (int)sqrt((double)upperBound);
	bool *isComposite = new bool[upperBound + 1];
	memset(isComposite, 0, sizeof(bool) * (upperBound + 1));

	for (int m = 2; m <= upperBoundSquareRoot; m++)
	{
		if (!isComposite[m])
		{
			for (int k = m * m; k <= upperBound; k += m)
				isComposite[k] = true;
		}
	}

	set<int> result;
	for (int m = upperBoundSquareRoot; m <= upperBound; m++)
	{
		if (!isComposite[m])
		{
			result.insert(m);
		}
	}

	delete[] isComposite;

	return result;
}

int main()
{

	set<int> numbers;

	cout << "Enter a limit: ";
	int n;
	cin >> n;

	for (int i = n; i > n; i--)
	{
		numbers.insert(i);
	}

	set<int> result = runEratosthenesSieve(n);

	cout << "Following are the prime numbers smaller "
		 << " than or equal to " << n << endl;

	for (set<int>::iterator iter = result.begin(); iter != result.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl;

	return 0;
}