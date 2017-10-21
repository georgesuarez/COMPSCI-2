/*
	Write functions
		set<int> set_union(set<int> a, set<int> b)
		set<int> intersection(set<int> a, set<int> b)
	that compute the set union and intersection of the sets a and b. (Don’t name the first
	function union—that is a reserved word in C++.)
*/
#include <iostream>
#include <set>
using namespace std;

set<int> set_union(set<int> a, set<int> b)
{
	set<int> result;
	set<int>::iterator iter;

	for (iter = a.begin(); iter != a.end(); iter++)
	{
		result.insert(*iter);
	}

	set<int>::iterator iter2;
	
	for (iter2 = b.begin(); iter2 != b.end(); iter2++)
	{
		result.insert(*iter2);
	}

	return result;
}

set<int> intersection(set<int> a, set<int> b)
{
	set<int> result;
	set<int>::iterator iter;
	set<int>::iterator iter2;

	for (iter = a.begin(); iter != a.end(); iter++)
	{
		for (iter2 = b.begin(); iter2 != b.end(); iter2++)
		{
			if (*iter == *iter2)
			{
				result.insert(*iter);
			}
		}
	}

	return result;
}

int main() {

	set<int> set1;
	set1.insert(1);
	set1.insert(2);
	set1.insert(5);

	set<int> set2;
	set2.insert(1);
	set2.insert(3);
	set2.insert(9);
	set2.insert(14);
	set2.insert(5);

	cout << "Set A: ";
	for (set<int>::iterator iter = set1.begin(); iter != set1.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl << endl;

	cout << "Set B: ";
	for (set<int>::iterator iter = set2.begin(); iter != set2.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl << endl;

	set<int> new_set = set_union(set1, set2);

	cout << "Set union: ";
	for (set<int>::iterator iter = new_set.begin(); iter != new_set.end(); iter++)
	{
		cout << *iter << " ";
	}

	set<int> new_set2 = intersection(set1, set2);

	cout << endl << endl;

	cout << "The intersection of the two sets: ";
	for (set<int>::iterator iter = new_set2.begin(); iter != new_set2.end(); iter++)
	{
		cout << *iter << " ";
	}

	cout << endl;

	return 0;
}