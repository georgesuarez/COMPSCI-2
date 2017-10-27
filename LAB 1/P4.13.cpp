/*
	Write a program that converts a Roman number such as MCMLXXVIII
	to its decimal number representation. Hint: First write a function that yields
	the numeric value of each of the letters. Then convert a string as follows: Look at
	the first two characters. If the first has a larger value than the second, then simply
	convert the first, call the conversion function again for the substring starting with
	the second character, and add both values. If the first one has a smaller value than
	the second, compute the difference and add to it the conversion of the tail. This
	algorithm will convert �Pig Roman� numbers like �IC�. Extra credit if you can
	modify it to process only genuine Roman numbers.
*/

#include <iostream>
#include <string>

using namespace std;

int convert(string &romanNumber)
{
	int length = romanNumber.length();
	int prev = 0;
	int index = 0;
	int sum = 0;
	bool invalid = false;

	while ((invalid == false) && (index < length))
	{
		switch (romanNumber[index])
		{
		case 'M':
			sum += 1000;
			if (prev < 1000)
			{
				sum -= 2 * prev;
			}
			prev = 1000;
			break;
		case 'D':
			sum += 500;
			if (prev < 500)
			{
				sum -= 2 * prev;
			}
			prev = 500;
			break;
		case 'C':
			sum += 100;
			if (prev < 100)
			{
				sum -= 2 * prev;
			}
			prev = 100;
			break;
		case 'L':
			sum += 50;
			if (prev < 50)
			{
				sum -= 2 * prev;
			}
			prev = 50;
			break;
		case 'X':
			sum += 10;
			if (prev < 10)
			{
				sum -= 2 * prev;
			}
			prev = 10;
			break;
		case 'V':
			sum += 5;
			if (prev < 5)
			{
				sum -= 2 * prev;
			}
			prev = 5;
			break;
		case 'I':
			sum += 1;
			if (prev < 1)
			{
				sum -= 2 * prev;
			}
			prev = 1;
			break;
		default:
			cout << romanNumber[index] << " is not a valid Roman Numeral" << endl;
			invalid = true;
			sum = 0;
		}
		index++;
	}

	return sum;
}

int main()
{

	cout << "Enter a Roman Numeral to conver to its decimal representation: ";
	string userInput;
	getline(cin, userInput);

	int result = convert(userInput);

	cout << endl;
	cout << "Roman number: " << userInput << " = " << result << endl
		 << endl;

	return 0;
}