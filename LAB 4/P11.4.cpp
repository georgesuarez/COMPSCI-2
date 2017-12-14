/*
        Modify the merge sort algorithm to sort a vector of employees by
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

void merge(vector<double> &a, vector<Employee *> &e, int from, int mid,
           int to) {

  int size = to - from + 1;
  vector<double> temp(size);
  vector<Employee *> e_temp(size);

  int i1 = from;
  int i2 = mid + 1;
  int j = 0;

  while (i1 <= mid && i2 <= to) {
    if (a[i1] < a[i2]) {
      temp[j] = a[i1];
      e_temp[j] = e[i1];
      i1++;
    } else {
      temp[j] = a[i2];
      e_temp[j] = e[i2];
      i2++;
    }
    j++;
  }

  while (i1 <= mid) {
    temp[j] = a[i1];
    e_temp[j] = e[i1];
    i1++;
    j++;
  }

  while (i2 <= to) {
    temp[j] = a[i2];
    e_temp[j] = e[i2];
    i2++;
    j++;
  }

  for (j = 0; j < size; j++) {
    a[from + j] = temp[j];
    e[from + j] = e_temp[j];
  }
}

void merge_sort(vector<double> &a, vector<Employee *> &e, int from, int to) {
  if (from == to)
    return;
  int mid = (from + to) / 2;
  merge_sort(a, e, from, mid);
  merge_sort(a, e, mid + 1, to);
  merge(a, e, from, mid, to);
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

  merge_sort(salaries, employees, 0, employees.size() - 1);

  cout << "Employee's sorted by their salaries: " << endl << endl;

  print_employees(employees);

  delete_employees(employees);

  cout << endl << endl;

  return 0;
}