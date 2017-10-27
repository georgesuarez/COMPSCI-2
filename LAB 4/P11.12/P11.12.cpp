/*
	Write a program that keeps an appointment book. Make a class
	Appointment that stores a description of the appointment, the appointment day, the
	starting time, and the ending time. Your program should keep the appointments in a
	sorted vector. Users can add appointments and print out all appointments for a
	given day. When a new appointment is added, use binary search to find where it
	should be inserted in the vector. Do not add it if it conflicts with another
	appointment.
*/
#include <iostream>
#include <string>
#include <vector>
#include "appointment.h"

using namespace std;

int main()
{

	vector<Appointment> appt_book;

	Appointment *master = new Appointment();

	Appointment a("Physical Check Up", 13, 7, 8);
	Appointment b("Vaccine Shots", 15, 4, 5);
	Appointment c("Prostate Exam", 14, 2, 3);

	appt_book.push_back(a);
	appt_book.push_back(b);
	appt_book.push_back(c);

	cout << "Enter the description of the appointment: ";
	string description;
	getline(cin, description);
	cout << endl;

	cout << "Enter the appointment day: ";
	int day;
	cin >> day;
	cout << endl;

	cout << "Enter the start time: ";
	int start_hr;
	cin >> start_hr;
	cout << endl;

	cout << "Enter the end time: ";
	int end_hr;
	cin >> end_hr;
	cout << endl;

	Appointment d(description, day, start_hr, end_hr);

	master->selection_sort(appt_book);

	master->insert(appt_book, d);

	master->selection_sort(appt_book);

	cout << "List of appointments sorted by day: " << endl;
	master->print_appt_book(appt_book);

	delete master;

	return 0;
}