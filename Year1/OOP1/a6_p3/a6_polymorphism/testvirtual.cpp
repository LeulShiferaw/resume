/*
	CH08-320142
	a6_p3.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"

/*
	     Area
	    /    \
	   v      v
	 Circle   Rectangle
	    |         |
	    v         v
	  Ring      Square
*/

const int num_obj = 7;
int main() {
	Area *list[num_obj];						// (1)An array of num_obj(in this case 6) Area pointers is being created
	int index = 0;								// (2)Initializing variable index to 0
	double sum_area = 0.0;						// (3)Initializing varialbe sum_area to 0
	double sum_perimeter = 0.0;
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// (4)Creating a ring of color "Blue", outer radius 5 and inner radius 2(thickness = 3). We are calling the constructor
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	cout << "Creating Square: ";
	Square red_square("RED", 10);
	list[0] = &blue_ring;						// (5)Since Ring was derived from Circle which was derived from Area the Ring pointer is type compatible with the Area pointer(polymorphism). The first pointer in list is pointing to blue_ring, then the second is point to yellow circle(which works based on the same principle) and so on...
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	list[6] = &red_square;
	while (index < num_obj) {					// (7)Go through size of list
		(list[index])->getColor();				// (8)Print the color of the current object and sum up the areas of all the objects
		sum_perimeter += list[index]->calcPerimeter();
		sum_area += (list[index++])->calcArea();// Post increment(return then add)
	}
	cout << "\nThe total area is "
			<< sum_area << " units ";	// (9)Print the total area
	cout << "\nThe total perimeter is " << sum_perimeter << " units " << endl;
	return 0;
}
