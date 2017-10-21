#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Appointment {

	public:
		Appointment() : day(0), start_hr(0), end_hr(0) {}
		Appointment(string desc, int new_day, int new_start_hr, int new_end_hr)
			: description(desc), day(new_day), start_hr(new_start_hr), end_hr(new_end_hr) {}
		
		string get_desc() const;
		int get_day() const;
		int get_start_hr() const;
		int get_end_hr() const;
		
		void selection_sort(vector<Appointment>& a);
		bool binary_search(vector<Appointment>& sorted_vec, int key);
		void insert(vector<Appointment>& a, Appointment& b);
		void swap(Appointment& a, Appointment& b);
		void print_appt_book(vector<Appointment>& a);

	private:
		string description;
		int day;
		int start_hr;
		int end_hr;
};


#endif