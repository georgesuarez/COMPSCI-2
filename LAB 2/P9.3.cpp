/*
        Write a program that reads an input file and displays the letter
   frequencies in that file. Such a tool will help a code breaker. If the most
   frequent letters in an encrypted file are H and K, then there is an excellent
   chance that they are the encryptions of E and T.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>


using namespace std;

int main() {

  cout << "Filename: ";
  string filename;
  getline(cin, filename);

  ifstream infile;

  infile.open(filename.c_str());

  if (infile.fail()) {
    cout << "Error opening file." << endl;
    exit(1);
  }

  int letter_freq[26] = {0};

  char c;
  while (infile.get(c)) {
    if (isalpha(c)) {
      c = toupper(c);

      int index = c - 'A';

      ++(letter_freq[index]);
    }
  }

  for (int i = 0; i < 26; ++i) {
    cout << " " << char(i + 'A') << " occurs " << setw(5) << letter_freq[i]
         << " times" << endl;
  }

  return 0;
}