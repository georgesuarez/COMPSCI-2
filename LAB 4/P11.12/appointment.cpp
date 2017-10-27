#include "appointment.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Appointment::get_desc() const
{
	return description;
}

int Appointment::get_day() const
{
	return day;
}

int Appointment::get_start_hr() const
{
	return start_hr;
}

int Appointment::get_end_hr() const
{
	return end_hr;
}

void Appointment::selection_sort(vector<Appointment> &a)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		int smallest = a[i].get_day();
		int smallest_index = i;

		for (unsigned int j = i; j < a.size(); j++)
		{
			if (a[j].get_day() < smallest)
			{
				smallest = a[j].get_day();
				smallest_index = j;
			}
		}
		swap(a[i], a[smallest_index]);
	}
}

bool Appointment::binary_search(vector<Appointment> &sorted_vec, int key)
{
	int left = 0;
	int mid = 0;
	int right = sorted_vec.size();

	while (left < right)
	{
		mid = left + (right - left) / 2;

		if (key > sorted_vec[mid].get_day())
		{
			left = mid + 1;
		}
		else if (key < sorted_vec[mid].get_day())
		{
			right = mid;
		}
		else
		{
			return true;
		}
	}

	return false;
}

void Appointment::insert(vector<Appointment> &vec, Appointment &b)
{
	Appointment *master = new Appointment();

	bool present = binary_search(vec, b.get_day());
	int pos = 0;

	if (present)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].get_day() == b.get_day())
			{
				pos = i;
				break;
			}
		}

		if ((vec[pos].get_end_hr() <= b.get_start_hr()) || (b.get_start_hr() <
																vec[pos].get_start_hr() &&
															b.get_end_hr() <= vec[pos].get_start_hr()))
		{
			vec.insert(vec.begin() + pos, b);
		}
		else
		{
			cout << "Time is conflicting with another appointment." << endl
				 << endl;
		}
	}
	else
	{
		vec.push_back(b);
	}
}

void Appointment::swap(Appointment &a, Appointment &b)
{
	Appointment temp = a;
	a = b;
	b = temp;
}

void Appointment::print_appt_book(vector<Appointment> &a)
{

	for (unsigned int i = 0; i < a.size(); i++)
	{
		cout << "Description: " << a[i].get_desc() << endl;
		cout << "Day: " << a[i].get_day() << endl;
		cout << "Start time: " << a[i].get_start_hr() << endl;
		cout << "End time: " << a[i].get_end_hr() << endl
			 << endl;
	}

	cout << endl;
}
