/*
	Implement a base class Account and derived classes Savings and
	Checking. In the base class, supply member functions deposit and withdraw. Provide
	a function daily_interest that computes and adds the daily interest. For calculations,
	assume that every month has 30 days. Checking accounts yield interest of 3
	percent monthly on balances over $1,000. Savings accounts yield interest of 6 percent
	on the entire balance. Write a driver program that makes a month�s worth of
	deposits and withdrawals and calculates the interest every day.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account
{
  public:
	Account();

	Account(double);

	Account(double, double);

	void set_deposit(double);

	void set_withdrawl(double);

	virtual double daily_interest();

	double get_amount();

  private:
	double amount;
	double deposit;
	double withdrawl;
};

Account::Account()
{
	amount = 0.0;
}

Account::Account(double new_amount)
{
	amount = new_amount;
}

Account::Account(double new_deposit, double new_withdrawl)
{
	deposit = new_deposit;
	withdrawl = new_withdrawl;
}

void Account::set_deposit(double new_amount)
{
	amount += new_amount;
}

void Account::set_withdrawl(double new_amount)
{
	amount -= new_amount;
}

double Account::daily_interest()
{
	return 0;
}

double Account::get_amount()
{
	return amount;
}

class Savings : public Account
{
  public:
	Savings();

	Savings(double);

	Savings(double, double);

	virtual double daily_interest();

  private:
	double interest;
	double min_balance;
};

Savings::Savings() : Account()
{
	interest = 0.06 / 30;
	min_balance = 0.0;
}

Savings::Savings(double new_amount) : Account(new_amount)
{
}

Savings::Savings(double new_deposit, double new_withdrawl)
	: Account(new_deposit, new_withdrawl)
{
}

double Savings::daily_interest()
{

	double new_amount = 0.0;

	new_amount = Account::get_amount() * interest;

	Account::set_deposit(new_amount);

	return new_amount;
}

class Checking : public Account
{
  public:
	Checking();

	Checking(double);

	Checking(double, double);

	virtual double daily_interest();

  private:
	double interest;
	double min_balance;
};

Checking::Checking() : Account()
{
	interest = 0.03 / 30;
	min_balance = 1000.00;
}

Checking::Checking(double new_amount) : Account(new_amount)
{
}

Checking::Checking(double new_deposit, double new_withdrawl)
	: Account(new_deposit, new_withdrawl)
{
}

double Checking::daily_interest()
{

	bool more = true;

	double new_amount = 0.0;

	if (Account::get_amount() - min_balance <= 0)
	{
		more = false;
		new_amount = 0.0;
	}
	else
	{
		new_amount = (Account::get_amount() - min_balance) * interest;
		Account::set_deposit(new_amount);
	}

	return new_amount;
}

int main()
{

	int days;
	double deposit;
	double withdrawl;
	bool more = true;
	Account *account1 = new Account();

	cout << "Enter 'Check' for checking account or 'Save' for savings account: ";
	string anwser;
	getline(cin, anwser);

	if (anwser == "Check")
	{
		Checking c1;
		account1 = &c1;
	}
	else if (anwser == "Save")
	{
		Savings s1;
		account1 = &s1;
	}
	else
	{
		cout << "Error: Account type does not exist" << endl;
		more = false;
	}

	if (more)
	{
		cout << "Enter the amount days you would like to make deposits/withdrawls: ";
		cin >> days;
		cout << endl;

		if (days < 1)
		{
			more = false;
		}
	}

	int n = 1;

	while (days > 0)
	{
		cout << "Enter the deposit for day " << n << " : ";
		cin >> deposit;
		cout << "Enter the withdrawl for day " << n << " : ";
		cin >> withdrawl;
		cout << endl;

		account1->set_deposit(deposit);
		account1->set_withdrawl(withdrawl);

		cout << "Daily interest earned: $" << fixed << setprecision(2) << account1->daily_interest() << endl;
		cout << "Remaing balance: $" << fixed << setprecision(2) << account1->get_amount() << endl;
		cout << endl;
		n++;
		days--;
	}

	cout << "Thanks for using our bank program!" << endl;

	return 0;
}