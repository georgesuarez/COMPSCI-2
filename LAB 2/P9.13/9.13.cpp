#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>


using namespace std;

int main() {
  string filename;
  cout << "Please enter the data file name: ";
  cin >> filename;
  ifstream infile;
  infile.open(filename.c_str());

  if (infile.fail()) {
    cout << "Error opening " << filename << endl;
    return 1;
  }

  char d[100];
  cout << "Enter the student id: ";
  cin >> d;
  const int MAX = 100;
  char str[MAX];
  int n;
  string filename1;

  while (infile) {
    infile >> filename1;
    ifstream infile1;
    infile1.open(filename1.c_str());

    while (infile1) {
      infile1.getline(str, MAX);
      n = strcmp(str, d);
      if (n == 0) {
        infile1.getline(str, MAX);
        cout << endl << filename1 << "\t" << str;
      }
    }
    infile1.close();
  }
  infile.close();

  return 0;
}
