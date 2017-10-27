/*
	Implement a class Person with the following fields:
		� the name
		� a pointer to the person�s best friend (a Person*)
		� a popularity counter that indicates how many other people have this person as their best friend
	
	Write a program that reads in a list of names, allocates a new Person for each of
	them, and stores them in a vector<Person*>. Then ask the name of the best friend
	for each of the Person objects. Locate the object matching the friend�s name and call
	a set_best_friend member function to update the pointer and counter. Finally,
	print out all Person objects, listing the name, best friend, and popularity counter for
	each.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{

  public:
	Person();

	Person(string newName);

	Person(string, Person *, int);

	~Person();

	string get_name();
	string get_best_friend();
	int get_popularity();
	void set_best_friend(Person *p);

  private:
	string name;
	int popularity;
	Person *bestFriend;
};

Person::Person()
{
	popularity = 0;
	bestFriend = 0;
}

Person::Person(string newName)
{
	name = newName;
	popularity = 0;
	bestFriend = 0;
}

Person::Person(string newName, Person *p, int newPopularity)
{
	name = newName;
	popularity = newPopularity;
	bestFriend = p;
}

void Person::set_best_friend(Person *p)
{
	bestFriend = p;
	(p->popularity)++;
}

string Person::get_name()
{
	return name;
}

string Person::get_best_friend()
{

	if (bestFriend != 0)
	{
		return bestFriend->name;
	}
	else
	{
		return "None";
	}
}

int Person::get_popularity()
{
	return popularity;
}

Person::~Person()
{
}

int main()
{

	Person *p1;
	string name;
	vector<Person *> friends;

	int num_of_friends;

	// Number of friends to add
	cout << "Enter how many friends you want to add: ";
	cin >> num_of_friends;

	// Fill the vector with Person objects
	while (num_of_friends > 0)
	{

		cout << "Enter a name: ";
		cin >> name;

		p1 = new Person(name);
		friends.push_back(p1);

		num_of_friends--;
	}

	cout << endl;
	unsigned int j;
	for (unsigned int i = 0; i < friends.size(); i++)
	{
		cout << "Who is " << friends[i]->get_name() << "'s best friend? ";
		cin >> name;

		// Search for best friend
		for (j = 0; j < friends.size(); j++)
			if (friends[j]->get_name() == name)
				break;

		// Found the best friend
		if (j < friends.size())
			friends[i]->set_best_friend(friends[j]);
		else
			cout << "Could not find your best friend " << name << endl;
	}

	cout << endl;

	cout << "List of friends: " << endl;

	cout << "================================" << endl;

	for (unsigned int i = 0; i < friends.size(); i++)
	{

		cout << "Name: " << friends[i]->get_name() << endl;
		cout << "Best Friend: " << friends[i]->get_best_friend() << endl;
		cout << "Popularity: " << friends[i]->get_popularity() << endl;
		cout << endl;
	}

	cout << "================================" << endl;

	for (unsigned int i = 0; i < friends.size(); i++)
	{

		delete friends[i];
	}

	return 0;
}