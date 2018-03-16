/*
	CH08-320142
	a5_p5.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <string>
#include "fraction.h"

using namespace std;

int main()
{
	Fraction a, b;

	try
	{
		cout << "Enter Fraction: ";
		cin >> a;
		cout << "Enter Fraction: ";
		cin >> b;
		cout << "Product: " << (a*b) << endl;
		cout << "Quotient: " << (a/b) << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	return 0;
}