#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
	cout << "Enter the text file name to be read, in current directory: ";

	string file;

	cin >> file;

	ifstream readFile;

	readFile.open(file.c_str(), ifstream::out);
	
	map<string, int> words;
	string word;

	while (readFile >> word)
	{
		map<string, int>::iterator pos = words.find(word);
		if (pos == words.end())
		{
			words[word] = 1;
		}
		else
		{
			(*pos).second++;
		}
	}

	map<string, int>::iterator iter;
	
	for (iter = words.begin(); iter != words.end(); iter++)
	{
		cout << iter->first << " appears " << iter->second << " times" << endl;
	}

	return 0;
}

