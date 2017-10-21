/*
	Write a program that prints instructions to get coffee, asking the user
	for input whenever a decision needs to be made. Decompose each task into a procedure,
	for example:
		
		void brew_coffee()
		{
			cout << "Add water to the coffee maker.\n";
			cout << "Put a filter in the coffee maker.\n";
			grind_coffee();
			cout << "Put the coffee in the filter.\n";
			...
		}
*/

#include <iostream>
#include <string>

using namespace std;

// Function Declarations

void get_ingredients();
// get_ingredients - prints instructions to get ingredients for coffee

void clean_coffee_maker();
// clean_coffee_maker - prints instructions to clean coffee maker

void brew_coffee();
// brew_coffee - prints instructions to brew coffee

void coffee_choice();
// coffee_choice - check if the user wants to use coffee beans or already has coffee ground

void grind_coffee();
// grind_coffee - prints instructions to grind cofffee

void collect_coffee();
// collect_coffee - collects coffee from coffee maker


int main() {
	cout << "**Coffee Making Instructions**" << endl;
	cout << endl;
	get_ingredients();

	brew_coffee();

	return 0;
}

// Function Definitions
void get_ingredients() {

	string input;
	cout << "Grab the cup that you going to use for your coffee." << endl;
	cout << "Grab a empty and clean coffee filter." << endl;
	cout << "Find the coffee maker that you are going to use." << endl;
	cout << endl;
	cout << "Is the coffee maker clean? (y/n) ";
	getline(cin, input);

	if (input == "y") {

		coffee_choice();
	}

	else {

		clean_coffee_maker();
	}
}

void clean_coffee_maker() {

	cout << endl;
	cout << "Grab a bottle of vinegar." << endl;
	cout << "Grab a empty and clean coffee filter." << endl;
	cout << "Insert the coffee filter inside the coffee maker" << endl;
	cout << "Pour the vinegar inside the coffee maker through the coffee filter." << endl;
	cout << "Turn your coffee maker on, and set it to brew." << endl;
	cout << endl;
	cout << "Is your coffee maker clean now? (y/n) ";
	string input;
	getline(cin, input);

	if (input == "y") {

		cout << endl;
		cout << "Toss out the vinegar from the coffee maker." << endl;
		coffee_choice();
	}

	else {

		cout << endl;
		cout << "Make sure the coffee maker is plugged in." << endl;
	}


}

void brew_coffee() {

	cout << "Add water to the coffee maker." << endl;
	cout << "Put the coffee filter inside the coffee maker." << endl;
	cout << "Put the coffee ground onto the coffee filter." << endl;
	cout << "Set the coffee maker to brew." << endl;
	cout << endl;
	cout << "Is the coffee maker done brewing? (y/n) ";
	string input;
	getline(cin, input);

	if (input == "y") {

		collect_coffee();
	}

	else {

		cout << endl;
		cout << "Grab your coffee cup and wait until it is done brewing." << endl;
		cout << "Then collect your coffee from the coffee maker, and enjoy." << endl;
	}

}

void grind_coffee() {

	cout << "Find the coffee grinder you are going to use." << endl;
	cout << "Insert the coffee beans inside the coffee grinder." << endl;
	cout << "Wait until the coffee grinder is done, and then collect your coffee ground." << endl;
}

void collect_coffee() {

	cout << endl;
	cout << "Grab your coffee cup." << endl;
	cout << "Collect the coffee from the coffee maker." << endl;
	cout << "Enjoy your cup of coffee." << endl;
}

void coffee_choice() {

	string input;
	cout << endl;
	cout << "Do you already have coffee ground? (y/n) ";
	getline(cin, input);

	if (input == "y") {

		cout << "Great, you are set." << endl;
		cout << endl;
	}

	else {
		cout << endl;
		cout << "Grab some coffee beans that you are going to grind." << endl;
		grind_coffee();
		cout << endl;
	}
}