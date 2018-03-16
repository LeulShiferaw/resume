/*
 * CH08-320143
 * a6_p4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include "fraction.h"

using namespace std;

int nPass=0,nFail=0;
void test(bool b)
{
	if(b) ++nPass;
	else ++nFail;
}

int main()
{
	//Exceptions
	//Should be invalid
	try
	{
		Fraction f1("1/0");
	}
	catch(const char* msg)
	{
		test(true);
		cout << msg;
	}
	//Should be invalid
	try
	{
		Fraction f1(1,2);
		Fraction f2(0,1);
		cout << f1/f2;
	}
	catch(const char* msg)
	{
		test(true);
		cout << msg;
	}

	cout << "NPass: " << nPass << endl;
	cout << "NFail: " << nFail << endl;
	return 0;
}
