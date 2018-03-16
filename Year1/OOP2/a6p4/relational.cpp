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

	cout << "NPass: " << nPass << endl;
	cout << "NFail: " << nFail << endl;
	return 0;
}
