/* 
	Write a program that computes the product of the first ten positive
    integers, 1 × 2 × … × 10, and the sum of the reciprocals . This is
	harder than it sounds. First, you need to know that the * symbol, not ×, is used for
    multiplication in C++. Try writing the program, and check the results against a
 	pocket calculator. The program’s results aren’t likely to be correct. Then write the
 	numbers as floating-point numbers, 1.0, 2.0, . . ., 10.0, and run the program again.
*/

#include <iostream>

int main() {

	int sumOfProducts = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10;
	int sumOfReciprocals = 1 / 1 + 1 / 2 + 1 / 3 + 1 / 4 + 1 / 5 + 1 / 6 + 1 / 7 + 1 / 8 + 1 / 9 + 1 / 10;
	double sum_of_products = 1.0 * 2.0 * 3.0 * 4.0 * 5.0 * 6.0 * 7.0 * 8.0 * 9.0 * 10.0;
	double sum_of_reciprocals = (1.0 / 1.0) + (1.0 / 2.0) + (1.0 / 3.0) + (1.0 / 4.0) + (1.0 / 5.0) + (1.0 / 6.0) + (1.0 / 7.0) + (1.0 / 8.0) + (1.0 / 9.0) + (1.0 / 10.0);
	
	std::cout << "Sum Of Products: " << sumOfProducts << std::endl;
	std::cout << "Sum of Reciprocals: " << sumOfReciprocals << std::endl;
	std::cout << "Sum Of Products using double: " << sum_of_products << std::endl;
	std::cout << "Sum Of Reciprocals using double: " << sum_of_reciprocals << std::endl;
	
	return 0;
}