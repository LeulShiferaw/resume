/*
	CH08-320142
	a3_p1.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-univeristy.de
*/

#include "City.h"

using namespace std;

int main()
{
	City Bremen, Paris, London;

	Bremen.setNh(546451);
	Bremen.setName("Bremen");
	Bremen.setMayor("Henning Scherf");

	Paris.setNh(2244000);
	Paris.setName("Paris");
	Paris.setMayor("Anne Hidalgo");

	London.setNh(8674000);
	London.setName("London");
	London.setMayor("Sadiq Khan");

	Bremen.print();
	cout << endl;

	Paris.print();
	cout << endl;

	London.print();

	return 0;
}