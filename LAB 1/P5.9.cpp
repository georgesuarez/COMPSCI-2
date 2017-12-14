/*
        Implement a class Student. For the purpose of this exercise, a student
        has a name and a total quiz score. Supply an appropriate constructor and
   functions get_name(), add_quiz(int score), get_total_score(), and
   get_average_score(). To compute the latter, you also need to store the number
   of quizzes that the student took.
*/

#include <iostream>
#include <string>

using namespace std;

class Student {

public:
  Student();

  Student(string, int);

  string get_name() const;

  void add_quiz(int);

  int get_total_score();

  int get_average_score();

private:
  string name;
  int score;
  int numberOfQuizzes;
};

Student::Student() {
  score = 0;
  numberOfQuizzes = 0;
}

Student::Student(string newName, int newScore) {
  name = newName;
  score = newScore;
  numberOfQuizzes = 1;
}

string Student::get_name() const { return name; }

void Student::add_quiz(int newScore) {
  numberOfQuizzes++;
  score += newScore;
}

int Student::get_total_score() { return score; }

int Student::get_average_score() { return get_total_score() / numberOfQuizzes; }

int main() {

  Student s1("George Suarez", 10);

  s1.add_quiz(9);
  s1.add_quiz(4);
  s1.add_quiz(7);
  s1.add_quiz(10);

  cout << "Student: " << s1.get_name() << endl;
  cout << "Total Quiz Score: " << s1.get_total_score() << endl;
  cout << "Average Quiz Score: " << s1.get_average_score() << endl;

  cout << endl << endl;

  return 0;
}