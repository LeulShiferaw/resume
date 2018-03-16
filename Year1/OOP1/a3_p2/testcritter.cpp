/*
	CH08-320142
	a3_p2.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include "Critter.h"

using namespace std;

int main()
{
	Critter c1;
	Critter c2("Leul1");
	Critter c3("Leul2", 10, 0);
	Critter c4("Leul3", 10, 0, 2);

	c1.setHunger(2);
	c2.setHunger(2);
	c3.setHunger(2);

	c1.print();
	c2.print();
	c3.print();
	c4.print();
	return 0;
}
