/*
        Derive a class Manager from Employee. Add a data field, named
        department, of type string. Supply a function print that prints the
   manager�s name, department, and salary. Derive a class Executive from
   Manager. Supply a function print that prints the string Executive, followed
   by the information stored in the Manager base object.
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Employee {
public:
  Employee();

  Employee(string, int);

  virtual void print() const;

private:
  string name;
  int age;
};

Employee::Employee() {
  name = "";
  age = 0;
}

Employee::Employee(string new_name, int new_age) {
  name = new_name;
  age = new_age;
}

void Employee::print() const {

  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
}

class Manager : public Employee {
public:
  Manager();

  Manager(string, int, string, double);

  void print() const;

private:
  string department;
  double salary;
};

Manager::Manager() : Employee() {
  department = "";
  salary = 0.0;
}

Manager::Manager(string new_name, int new_age, string new_department,
                 double new_salary)
    : Employee(new_name, new_age) {

  department = new_department;
  salary = new_salary;
}

void Manager::print() const {

  Employee::print();

  cout << "Department: " << department << endl;
  cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
}

class ExecManager : public Manager {
public:
  ExecManager();

  ExecManager(string, int, string, double);

  void print() const;
};

ExecManager::ExecManager() : Manager() {}

ExecManager::ExecManager(string new_name, int new_age, string new_department,
                         double new_salary)
    : Manager(new_name, new_age, new_department, new_salary) {}

void ExecManager::print() const {

  cout << "Executive: " << endl;
  Manager::print();
}

int main() {

  ExecManager *exec1 =
      new ExecManager("Hacker Harry", 40, "Business", 70000.00);

  exec1->print();

  cout << endl;

  delete exec1;

  return 0;
}