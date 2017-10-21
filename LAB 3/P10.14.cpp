#include <iostream>
#include <vector>
#include <string>

using namespace std;

int attempts = 0;

void hanoi(int n,int one, int two, int three)
{
	attempts++;
	if (n == 1)
	{
		cout << "Move disk from peg "<< one << " to peg " << three << endl;
	}
	else
	{
		hanoi(n-1, one, three, two);
		cout << "Move disk from peg "<< one << " to peg " << three << endl;
		hanoi(n-1, two, one, three);
	}
}

int main()
{
	int number_of_disks;
	int x = 1;
	int y = 2;
	int z = 3;
	
	cout << "This program will tell you how to solve the tower of hanoi" << endl;
	cout << "and how many moves it takes!" << endl;
	
	cout << "How many disks? ";
	cin >> number_of_disks;
	cout << endl;
	
	hanoi(number_of_disks,x,y,z);
	cout << "It took " << attempts << " attempts to solve!" << endl << endl;
	return 0;
}
