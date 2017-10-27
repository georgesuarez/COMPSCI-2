/* 
	Write a function
	void downsize(list<string>& names)
	that removes every second value from a linked list.
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

void downsize(list<string> &names)
{
	list<string>::iterator query = names.begin();
	query++;
	names.erase(query);
	query = names.begin();
}

int main()
{

	list<string> names;

	names.push_back("George");
	names.push_back("Henry");
	names.push_back("Erik");
	names.push_back("Tim");
	names.push_back("Bryan");
	names.push_back("Hacker Harry");

	list<string>::iterator print;

	cout << "Orignal list of names: " << endl;
	for (print = names.begin(); print != names.end(); print++)
	{
		cout << *print << endl;
	}

	cout << endl;

	downsize(names);
	downsize(names);
	downsize(names);

	cout << "After downsizing the list: " << endl;
	for (print = names.begin(); print != names.end(); print++)
	{
		cout << *print << endl;
	}

	cout << endl;

	return 0;
}