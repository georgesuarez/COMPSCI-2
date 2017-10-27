/*
	Exercise P10.1. If a string has n letters, then the number of permutations is given by
	the factorial function:

							n! = 1 × 2 × 3 ×...× n
	For example, 3! = 1 x 2 x 3 = 6 and there are six permutations of the three-character
	string "eat". Implement a recursive factorial function, using the definitions

								n! = (n − 1)! × n
	and
										0! = 1
*/

#include <iostream>
#include <string>

using namespace std;

int factorial(int n)
{
	int temp = 0;

	if (n <= 1)
		return 1;

	temp = n * factorial(n - 1);

	return temp;
}

int main()
{

	cout << "Enter a string: ";
	string word;
	getline(cin, word);

	int permuatations = factorial(word.length());

	cout << "The word " << word << " has "
		 << permuatations << " permuatations." << endl;

	return 0;
}