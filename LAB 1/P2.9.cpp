/*
	Giving change. Implement a program that directs a cashier how to
	give change. The program has two inputs: the amount due and the amount received
	from the customer. It should compute the difference, and compute the dollars,
	quarters, dimes, nickels, and pennies that the customer should receive in return.
	
	Hint: First transform the difference into an integer balance, denominated in pennies.
	Then compute the whole dollar amount. Subtract it from the balance. Compute
	the number of quarters needed. Repeat for dimes and nickels. Display the
	remaining pennies.
*/
#include <iostream>

using namespace std;

int main()
{

	cout << "Enter The Amount Due: ";
	double amt_due;
	cin >> amt_due;

	cout << "Enter The Amount Recieved: ";
	double amt_recieved;
	cin >> amt_recieved;

	double amt_balance = amt_recieved - amt_due;

	int difference = static_cast<int>(amt_balance * 100);

	cout << "Give $" << difference / 100.00 << " in change as follows: " << endl;

	int quarters = difference / 25;

	cout << quarters << " quarters." << endl;

	difference = difference % 25;

	int dimes = difference / 10;

	cout << dimes << " dimes." << endl;

	difference = difference % 10;

	int nickels = difference / 5;

	difference = difference % 5;

	cout << nickels << " nickels." << endl;

	int pennies = difference;

	cout << pennies << " pennies." << endl;

	return 0;
}