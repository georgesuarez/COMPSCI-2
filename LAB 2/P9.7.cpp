#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "ccc_empl.h"

using namespace std;

const int NEWLINE_LENGTH = 2;
const int RECORD_SIZE = 30 + 10 + NEWLINE_LENGTH;

double string_to_double(string s)
{
	istringstream instr(s);
	double x;
	instr >> x;
	return x;
}

void raise_salary(vector<Employee> &employees, double percent)
{
	for (unsigned int i = 0; i < employees.size(); i++)
	{
		double new_salary = employees[i].get_salary() * (1 + percent / 100.0);
		employees[i].set_salary(new_salary);
	}
}

void lower_salary(vector<Employee> &employees, double percent)
{
	for (unsigned int i = 0; i < employees.size(); i++)
	{
		double new_salary = employees[i].get_salary() * (1 - percent / 100.0);
		employees[i].set_salary(new_salary);
	}
}

void read_employee(Employee &e, vector<Employee> &employees, istream &in)
{
	if (in.fail())
	{
		cerr << "Error reading file. " << endl;
		return;
	}

	string line;
	while (getline(in, line))
	{
		string name = line.substr(0, 30);
		double salary = string_to_double(line.substr(30, 10));
		e = Employee(name, salary);
		employees.push_back(e);
	}
}

void write_employee(vector<Employee> &employees, ostream &out)
{
	while (!out.eof())
	{
		for (unsigned int i = 0; i < employees.size(); i++)
		{
			out << employees[i].get_name()
				<< setw(10 + (30 - employees[i].get_name().length()))
				<< fixed << setprecision(2)
				<< employees[i].get_salary();
		}
	}
}

int main()
{

	int user_input = 0;
	cout << "Please enter the data file name: ";
	string filename;
	cin >> filename;
	fstream fs;
	fs.open(filename.c_str());
	fs.seekg(0, ios::end); // Go to end of file

	cout << "1. Raise salaries " << endl;
	cout << "2. Lower salaries " << endl;
	cout << "3. Quit " << endl;
	cout << "Select an option: ";
	cin >> user_input;

	if (user_input == 1)
	{
		cout << endl;
		Employee e;
		vector<Employee> employees;

		cout << "Enter a percentage: ";
		double salary_percentage;
		cin >> salary_percentage;
		cout << endl;

		fs.seekg(RECORD_SIZE, ios::beg);
		read_employee(e, employees, fs);
		raise_salary(employees, salary_percentage);

		cout << "Employee's name & new salaries: " << endl;
		for (unsigned int i = 0; i < employees.size(); i++)
		{
			cout << employees[i].get_name() << fixed << setprecision(2)
				 << " " << employees[i].get_salary() << endl;
		}

		fs.seekp(RECORD_SIZE, ios::beg);
		write_employee(employees, fs);
		cout << endl
			 << endl;
	}

	else if (user_input == 2)
	{
		cout << endl;

		Employee e;
		vector<Employee> employees;

		cout << "Enter a percentage: ";
		double salary_percentage;
		cin >> salary_percentage;
		cout << endl;

		fs.seekg(RECORD_SIZE, ios::beg);
		read_employee(e, employees, fs);
		lower_salary(employees, salary_percentage);

		cout << "Employee's name & new salaries: " << endl;
		for (unsigned int i = 0; i < employees.size(); i++)
		{
			cout << employees[i].get_name() << fixed << setprecision(2)
				 << " " << employees[i].get_salary() << endl;
		}
		cout << endl;
	}

	fs.close();

	return 0;
}