/*
	CH08-320142
	a4_p5.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Shapes.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  Circle c("Circle", 3, 4, 7);
  Rectangle r("Rectangle", 3, 4, 2, 3);
  Square s("Square", 3, 4, 4);

  cout << "Circle Perimeter and Area: " << c.perimeter() << " " << c.area() << endl;
  cout << "Rectangle Perimeter and Area: " << r.perimeter() << " " << r.area() << endl;
  cout << "Square Perimeter and Area: " << s.perimeter() << " " << s.area() << endl;
}