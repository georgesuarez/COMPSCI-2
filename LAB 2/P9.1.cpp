/*
        Write a program that asks the user for a file name and displays the
        number of characters, words, and lines in that file. Then have the
   program ask for the name of the next file. When the user enters a file that
   doesn�t exist(such as the empty string), the program should exit.
*/
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

int main() {

  bool more = true;
  int words = 0;
  int chars = 0;
  int lines = 0;

  while (more) {

    cout << "Enter the filename: ";
    string filename;
    getline(cin, filename);

    if (filename == "") {
      cout << "File does not exist." << endl;
      exit(1);
    }

    ifstream infile;

    infile.open(filename.c_str());

    if (infile.fail()) {
      cout << "Error opening file." << endl;
      more = false;
    }

    string data;

    while (infile >> data) {
      if (infile.peek() == '\n')
        ++lines;
      chars += data.length();
      ++words;
    }

    cout << endl;
    cout << "Number of characters: " << chars << endl;
    cout << "Number of words: " << words << endl;
    cout << "Number of lines: " << lines << endl;

    cout << endl;
  }

  return 0;
}