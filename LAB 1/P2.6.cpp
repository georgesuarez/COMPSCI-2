/* 	Write a program that asks the user for the lengths of the sides of a
        rectangle.Then print
        � The area and perimeter of the rectangle
        � The length of the diagonal(use the Pythagorean theorem)
*/

#include <cmath>
#include <iostream>


int main() {

  std::cout << "Enter the sides of the rectangle: ";
  double a_1, a_2, b_1, b_2;
  std::cin >> a_1 >> b_1 >> a_2 >> b_2;

  double area = a_1 * b_1;
  double perimeter = a_1 + a_2 + b_1 + b_2;
  double diagonal = std::sqrt((a_1 * a_1) + (b_1 * b_1));

  std::cout << "Area: " << area << std::endl;
  std::cout << "Perimeter: " << perimeter << std::endl;
  std::cout << "Diagonal = " << diagonal << std::endl;

  return 0;
}