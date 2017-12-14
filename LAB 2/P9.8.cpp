/*
        The program in Section 9.6 asks the user to specify the record number.
        More likely than not, a user has no way of knowing the record number.
   Write a program that asks the user for the name of an employee, finds the
   record with that name, and displays the record. Then the program should give
   the following options to the user: � Change the salary of this record � View
   the next record � Find another employee � Quit
*/

#include "ccc_empl.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

const int NEWLINE_LENGTH = 2;
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;

int main() {

  cout << "Please enter the data file name: ";
  string filename;
  cin >> filename;
  cin.ignore();

  fstream fs;
  fs.open(filename.c_str());
  fs.seekg(0, ios::end); // Go to end of file

find:

  int n_record = fs.tellg() / RECORD_SIZE;

  int pos;

  fs.seekg(0, ios::beg);

  string data;
  int lines = 0;
  int i;
  int num = 2 * n_record + 2;
  bool b = false;

  cout << "Enter the employee name: ";
  string employee_name;
  getline(cin, employee_name);

  while (fs >> data) {
    lines++;

    for (i = 0; employee_name[i] != '\0'; i++) {
      b = true;
      if (employee_name[i] != data[i]) {
        b = false;
        break;
      }
    }

    if (b == true) {
      num = lines;
      break;
    }
  }

  pos = num / 2;

  if (pos > n_record) {
    cout << "You entered a wrong number that is not exit" << endl;
    exit(1);
  }

  int s;
  int n, count = 0;
  int r = 0;
  const int MAX = 100;
  char str[MAX];

  fs.seekg(pos * RECORD_SIZE, ios::beg);

  fs.getline(str, MAX);

  cout << str << endl << endl;

  for (int i = 30; i < 40; i++) {
    if (str[i] != ' ') {
      count++;
    }
  }

  int c = count;
  int m, sum = 1, u;
  m = c;

  int user_input = 0;

  cout << "1. Change the salary of this record" << endl;
  cout << "2. View the next record" << endl;
  cout << "3. Find another employee" << endl;
  cout << "4. Quit " << endl;
  cout << "Select an option: ";
  cin >> user_input;
  cin.ignore();

  if (user_input == 1) {
    cout << "Enter a percentage to update the record with: ";
    cin >> s;

    for (int j = 0; j < c; j++) {
      for (int i = 0; i < m - 1; i++) {
        sum *= 10;
      }

      u = (str[30 + j] - 48) * sum;
      r = r + u;
      m--;
      sum = 1;
    }

    int k = ((r * s) / 100) + r;

    cout << "Updataed salary = " << k << endl;

    fs.seekg((pos * RECORD_SIZE) + 30, ios::beg);

    fs << k;
  }

  if (user_input == 2) {
    if (pos + 1 < n_record) {
      fs.getline(str, MAX);
      cout << "Next record is: " << str << endl << endl;
    } else {
      cout << "Next record is not present." << endl;
    }
  }
  if (user_input == 3)
    goto find;

  fs.seekp(pos * RECORD_SIZE, ios::beg);
  fs.close();

  return 0;
}