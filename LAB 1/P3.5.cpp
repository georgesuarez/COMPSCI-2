/*
	Write a program that translates a number between 0 and 4 into the
	letter grade. For example, the number 2.8 (which might have been the average
	of several grades) would be converted to B–. Break ties in favor of the better
	grade; for example 2.85 should be a B.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	double grade_value;

	cout << "Enter a grade score: ";
	cin >> grade_value;

	string grade;

	if (grade_value > 4.0 || grade_value < 0)
	{
		cout << "The grade score has to be between 4.0 and 0.0" << endl;
	}

	if (grade_value == 4.0 || grade_value >= 3.85)
	{
		grade = "A";
	}
	else if (grade_value < 3.85 && grade_value >= 3.7)
	{
		grade = "A-";
	}
	else if (grade_value == 3.3 || grade_value > 3)
	{
		grade = "B+";
	}
	else if (grade_value == 3 || grade_value >= 2.85)
	{
		grade = "B";
	}
	else if (grade_value < 2.85 && grade_value >= 2.7)
	{
		grade = "B-";
	}
	else if (grade_value == 2.3 && grade_value > 2)
	{
		grade = "C+";
	}
	else if (grade_value == 2 || grade_value >= 1.85)
	{
		grade = "C";
	}
	else if (grade_value < 1.85 && grade_value >= 1.7)
	{
		grade = "C-";
	}
	else if (grade_value == 1.3 && grade_value > 1)
	{
		grade = "D+";
	}
	else if (grade_value == 1 || grade_value >= 0.85)
	{
		grade = "D";
	}
	else if (grade_value < 0.85 && grade_value >= 0.7)
	{
		grade = "D-";
	}
	else
	{
		grade = "F";
	}

	cout << "Your grade is: " << grade << endl;

	return 0;
}