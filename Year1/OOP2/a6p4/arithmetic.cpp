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
	//Arithmetic
	Fraction f1(1,3);
	Fraction f2(1,2);

	test((f1+f2)==Fraction(5,6));
	test(f1-f2==Fraction(-1,6));
	test(f1*f2==Fraction(1,6));
	test(f1/f2==Fraction(2,3));

	cout << "NPass: " << nPass << endl;
	cout << "NFail: " << nFail << endl;
	return 0;
}
