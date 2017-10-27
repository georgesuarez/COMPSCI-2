/**
	Junk mail. Write a program that reads in two files: a template and a
	database. The template file contains text and tags. The tags have the form |1| |2|
	|3|� and need to be replaced with the first, second, third, � field in the current
	database record.

	A typical database looks like this:
	Mr.|Harry|Hacker|1105 Torre Ave.|Cupertino|CA|95014
	Dr.|John|Lee|702 Ninth Street Apt. 4|San Jose|CA|95109
	Miss|Evelyn|Garcia|1101 S. University Place|Ann Arbor|MI|48105 

And here is a typical form letter:
	To:
	|1| |2| |3|
	|4|
	|5|, |6| |7|
	
	Dear |1| |3|:
	You and the |3| family may be the lucky winners of $10,000,000 in the C++
	compiler clearinghouse sweepstakes! ...
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

	ifstream database;

	database.open("database.txt");

	if (database.fail())
	{
		cout << "Error opening: database.txt" << endl;
		exit(1);
	}

	cout << "Enter the filename: ";
	string filename;
	getline(cin, filename);

	fstream inFile;

	inFile.open(filename.c_str());

	if (inFile.fail())
	{
		cout << "Error opening: " << filename << endl;
		exit(1);
	}

	vector<string> info;

	string data;
	while (getline(database, data, '|'))
	{
		info.push_back(data);
	}

	database.close();

	ofstream output("output.txt");

	string more_data;

	while (getline(inFile, more_data))
	{
		size_t pos = more_data.find("|1| |2| |3|");
		if (pos != string::npos)
		{
			more_data.replace(pos, more_data.length(), info[0] + " " + info[1] + " " + info[2]);
		}

		size_t pos2 = more_data.find("|4|");
		if (pos2 != string::npos)
		{
			more_data.replace(pos2, more_data.length(), info[3]);
		}

		size_t pos3 = more_data.find("|5|, |6| |7|");
		if (pos3 != string::npos)
		{
			more_data.replace(pos3, more_data.length(), info[4] + ", " + info[5] + " " + info[6]);
		}

		size_t pos4 = more_data.find("Dear |1| |3|:");
		if (pos4 != string::npos)
		{
			more_data.replace(pos4, more_data.length(), "Dear " + info[0] + " " + info[2]);
		}
		size_t pos5 = more_data.find("You and the |3| family may be the lucky winners of $10,000,000 in the C++");
		if (pos5 != string::npos)
		{
			more_data.replace(pos5, more_data.length(), "You and the " + info[2] + " family may be the lucky winners of $10,000,000 in the C++");
		}

		output << more_data << endl;
		cout << more_data << endl;
	}

	inFile.close();
	output.close();

	return 0;
}
