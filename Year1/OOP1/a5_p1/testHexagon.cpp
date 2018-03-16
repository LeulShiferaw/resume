/*
	CH08-320142
	a5_p1.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Shapes.h"
#include <iostream>

using namespace std;

int main()
{
	Hexagon h1("Hexagon 1", 0, 0, 6, 6, "red");
	Hexagon h2("Hexagon 2", 0, 0, 6, 11, "yellow");
	Hexagon h3(h2);

	cout << "Perimeter and area h1: " << h1.perimeter() << " " << h1.area() << endl;
	cout << "Perimeter and area h2: " << h2.perimeter() << " " << h2.area() << endl;
	cout << "Perimeter and area h1: " << h3.perimeter() << " " << h3.area() << endl;
	return 0;
}