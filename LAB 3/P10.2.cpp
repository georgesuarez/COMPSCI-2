/*
        Write a recursive function void reverse() that reverses a sentence.
        For example:
                Sentence greeting = new Sentence("Hello!");
                greeting.reverse();
                cout << greeting.get_text() << "\n";

        prints the string "!olleH". Implement a recursive solution by removing
   the first character, reversing a sentence consisting of the remaining text,
   and combining the two.
*/
#include <iostream>
#include <string>

using namespace std;

class Sentence {
public:
  Sentence();

  Sentence(string new_word);

  string get_text() const;

  string reverse(string &s1);

private:
  string word;
};

Sentence::Sentence(){};

Sentence::Sentence(string new_word) { word = new_word; }

string Sentence::get_text() const { return word; }

string Sentence::reverse(string &s1) {
  if (s1.length() == 1) {
    return s1;
  } else {
    return reverse(s1.substr(1, s1.length())) + s1.at(0);
  }
}

int main() {
  string word;
  cout << "Enter your word: ";
  getline(cin, word);

  Sentence *greeting = new Sentence(word);

  cout << endl;
  cout << "Your word is: " << greeting->get_text() << endl;
  cout << endl;

  cout << "Your word in reversed: " << greeting->reverse(word) << endl;
  cout << endl;

  return 0;
}
