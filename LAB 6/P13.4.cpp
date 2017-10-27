#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	ifstream readFile;

	cout << "Enter the filename: ";
	string fileName;
	cin >> fileName;

	readFile.open(fileName.c_str(), ifstream::out);

	multiset<string> words;

	string word;
	while (readFile >> word)
	{
		words.insert(word);
	}

	set<string> duplicates;

	for (multiset<string>::iterator iter = words.begin(); iter != words.end(); iter++)
	{
		if (duplicates.count(*iter) == 0)
		{
			cout << *iter << " appears " << words.count(*iter) << " times" << endl;
			duplicates.insert(*iter);
		}
	}

	cout << endl;

	return 0;
}