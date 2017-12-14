/*
        Modify the selection sort algorithm to sort a vector of employees by
        salary.
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Employee {

public:
  Employee();

  Employee(string, string, double);

  double get_salary() const;

  string get_name() const;

private:
  double salary;

  string first_name;

  string last_name;
};

Employee::Employee() { salary = 0.0; }

Employee::Employee(string new_first_name, string new_last_name,
                   double new_salary) {
  first_name = new_first_name;
  last_name = new_last_name;
  salary = new_salary;
}

double Employee::get_salary() const { return salary; }

string Employee::get_name() const { return first_name + " " + last_name; }

void swap(int &a, int &b) {
  int temp = 0;
  temp = a;
  a = b;
  b = temp;
}

void selection_sort(vector<double> &a, vector<Employee *> &e) {
  for (unsigned int i = 0; i < a.size(); i++) {
    int smallest = a[i];
    int smallest_index = i;

    for (unsigned int k = i; k < a.size(); k++) {
      if (a[k] < smallest) {
        smallest = a[k];
        smallest_index = k;
      }
    }
    swap(a[i], a[smallest_index]);
    swap(e[i], e[smallest_index]);
  }
}

void print_employees(vector<Employee *> &e) {
  for (unsigned int i = 0; i < e.size(); i++) {
    cout << "Name: " << e[i]->get_name() << endl
         << "Salary: " << fixed << setprecision(2) << e[i]->get_salary() << endl
         << endl;
  }
}

void delete_employees(vector<Employee *> &e) {
  for (unsigned int i = 0; i < e.size(); i++) {
    delete e[i];
  }
}

int main() {

  ifstream inFile;

  inFile.open("employee_info.txt");

  if (inFile.fail()) {
    cerr << "Error: File could not be opened." << endl;
    exit(1);
  }

  string first_name, last_name;
  double salary;

  vector<Employee *> employees;

  while (inFile >> first_name >> last_name >> salary) {

    Employee *e = new Employee(first_name, last_name, salary);

    employees.push_back(e);
  }

  vector<double> salaries;

  for (unsigned int i = 0; i < employees.size(); i++) {
    salaries.push_back(employees[i]->get_salary());
  }

  cout << "Employee's Names and Salaries: " << endl << endl;
  print_employees(employees);

  cout << endl << endl;

  selection_sort(salaries, employees);

  cout << "Employee's sorted by their salaries: " << endl << endl;

  print_employees(employees);

  delete_employees(employees);

  cout << endl << endl;

  return 0;
}