/*
	CH08-320142
	a6_p2.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <string>
#include "fraction.h"

using namespace std;

int main()
{
	Fraction a, b, c;

	try
	{
		cout << "Enter Fraction: ";
		cin >> a;
		cout << "Enter Fraction: ";
		cin >> b;

		if(a > b)
			cout << "Greater/equal Fraction: " << a << endl;
		else cout << "Greater/equal Fraction: " << b << endl;

		c = (a + b);
		cout << "Sum: " << c << endl;
		c = (a - b);
		cout << "Difference: " << c << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	return 0;
}