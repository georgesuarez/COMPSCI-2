/*
	Implement a class Address. An address has a house number, a street, an
	optional apartment number, a city, a state, and a postal code. Supply two constructors:
	one with an apartment number and one without. Supply a print function that
	prints the address with the street on one line and the city, state, and postal code on
	the next line. Supply a member function comes_before that tests whether one
	address comes before another when the addresses are compared by postal code.
*/

#include <iostream>
#include <string>

using namespace std;

class Address
{

  public:
	// Constructor
	Address();

	// Overload Constructor
	Address(int house_num, string street, string city, string state, string postal_code);

	Address(int house_num, string street, int apartment_num, string city, string state, string postal_code);

	// Accessor Functions
	void print_address() const;

	string comes_before(Address a);

  private:
	string street, city, state, postal_code;
	int apartment_num, house_num;
};

Address::Address()
{
	house_num = 0;
	apartment_num = 0;
}

Address::Address(int new_house_num, string new_street, string new_city, string new_state, string new_postal_code)
{
	house_num = new_house_num;
	street = new_street;
	city = new_city;
	state = new_state;
	postal_code = new_postal_code;
}

Address::Address(int new_house_num, string new_street, int new_apartment_num, string new_city, string new_state, string new_postal_code)
{
	house_num = new_house_num;
	street = new_street;
	apartment_num = new_apartment_num;
	city = new_city;
	state = new_state;
	postal_code = new_postal_code;
}

void Address::print_address() const
{

	cout << "Address: " << house_num << " " << street << endl;
	cout << "City: " << city << endl;
	cout << "State: " << state << endl;
	cout << "Postal Code: " << postal_code << endl;
}

string Address::comes_before(Address a)
{

	if (postal_code.compare(a.postal_code) < 0)
	{

		return postal_code;
	}

	else if (postal_code.compare(a.postal_code) > 0)
	{

		return a.postal_code;
	}

	else
	{

		return postal_code = a.postal_code;
	}
}

int main()
{

	Address address1(1243, "Elm St.", "Fontana", "CA", "92337");

	address1.print_address();

	cout << endl;

	Address address2(4321, "Haven Ave", 44, "Rancho Cucamonga", "CA", "91737");

	cout << endl;

	address2.print_address();

	cout << endl;

	cout << "Postal Code: " << address1.comes_before(address2) << " comes first." << endl;

	return 0;
}