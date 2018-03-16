/*
 * CH08-320143
 * a6_p3.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include "fraction.h"

using namespace std;

int nPass=0;
int nFail=0;

void test(bool b)
{
	if(b) ++nPass;
	else ++nFail;
}

int main()
{
	//Relational
	Fraction f1(1,3);
	Fraction f2(1,2);
	
	test(f1<f2);	
	test(f1<=f2);
	test(f1<=f1);
	test(f2>f1);
	test(f2>=f1);
	test(f2>=f2);

	Fraction f3("+1/+3");
	test(f1==f3);
	test(f1!=f2);

	//Arithmetic
	test((f1+f2)==Fraction(5,6));
	test(f1-f2==Fraction(-1,6));
	test(f1*f2==Fraction(1,6));
	test(f1/f2==Fraction(2,3));

	//Input and output stream
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

	//Exceptions
	//Should be invalid
	try
	{
		Fraction f4("1/0");
	}
	catch(const char* msg)
	{
		test(true);
		cout << msg;
	}
	//Should be invalid
	try
	{
		Fraction f5(1,2);
		Fraction f6(0,1);
		cout << f5/f6;
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
