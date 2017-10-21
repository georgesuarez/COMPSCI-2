/*
	Write a function that computes the average value of an array of floating-
	point data:
		
		double average(double* a, int a_size)
	
	In the function, use a pointer variable, and not an integer index, to traverse the array
	elements.
*/

#include <iostream>

using namespace std;

double average(double* a, int a_size) {

	double sum = 0.0;

	for (int i = 0; i < a_size; i++) {

		 sum += *(a + i);
	}

	return sum / a_size;
}

int main() {

	int a_size;
	cout << "How many numbers do you want?: ";
	cin >> a_size;

	double* values = new double[a_size];

	cout << "Enter your numbers: " << endl;

	for (int i = 0; i < a_size; ++i) {
		cin >> *(values + i);
	}

	double sum = average(values, a_size);

	cout << "Average: " << sum << endl;

	return 0;
}