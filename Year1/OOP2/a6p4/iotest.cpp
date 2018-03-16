/*
 * CH08-320143
 * a6_p4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-univeristy.de
 */

#include "fraction.h"

using namespace std;

int main()
{
	//Input and output stream
	Fraction f1(1,3);
	cout << f1 << "==" << "1/3" << endl;
	try
	{
		cout << "Enter num and den: " << endl;
		cin >> f1;
		cout << "Your input is: " << f1 << endl;
	}
	catch(const char* msg)
	{
		cout << msg;
	}
	return 0;
}
