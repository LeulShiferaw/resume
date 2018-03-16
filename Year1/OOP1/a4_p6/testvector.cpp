/*
	CH08-320142
	a4_p6.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{
	Vector a(3), c;

	for(int i = 0; i<3; ++i)
		a.set(i, i);	
	
	Vector b(a);

	c.set_s(a.get_s());
	for(int i = 0; i < 3; ++i)
		c.set(i, i+3);

	cout << "A: ";
	a.print();

	cout << "B: ";
	b.print();

	cout << "C: ";
	c.print();

	cout << endl;

	cout << "Norm A: " << a.norm() << endl;

	cout << "A * C: ";
	cout << a.dot(c) << endl;

	cout << "A + C: ";
	a.add(c).print();

	cout << "A - C: ";
	a.diff(c).print();

	return 0;
}