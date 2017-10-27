#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool find(const string &s, const string &t)
{
	if (s.length() < t.length())
		return false;
	else if (s.substr(0, t.size()) == t)
		return true;

	return find(s.substr(1), t);
}

int main()
{

	cout << boolalpha << find("mississipi", "sip") << endl;
	cout << boolalpha << find("suck", "eggs") << endl
		 << endl;

	return 0;
}
