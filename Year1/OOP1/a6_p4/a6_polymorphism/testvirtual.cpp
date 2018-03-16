/*
	CH08-320142
	a6_p4.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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
#define FOR(i, e) for(i = 0; i<e; ++i)
int rand_range(const int &l, const int &h)
{
	return l + rand()%(h-l+1);
}

char* rand_color()
{	
	switch(rand_range(1, 4))
	{
		case 1: return "RED";
		case 2: return "VIOLET";
		case 3: return "BLUE";
		case 4: return "BLACK";
	}
	return "JUSTTOAVOIDWARNING";
}

const int num_obj = 7;
int main() {
	Area *list[30];
	
	int i;
	FOR(i, 30)
	{
		cout << i+1 << endl;
		switch(rand_range(1, 4))
		{
		case 1:
			cout << "Creating Rectangle: ";
			list[i] = new Rectangle(rand_color(), rand_range(1, 100), rand_range(1, 100));
			break;
		case 2:
			cout << "Creating Ring: ";
			list[i] = new Ring(rand_color(), rand_range(1, 100), rand_range(1, 100));
			break;
		case 3:
			cout << "Creating Circle: ";
			list[i] = new Circle(rand_color(), rand_range(1, 100));
			break;
		case 4:
			cout << "Creating Square: ";
			list[i] = new Square(rand_color(), rand_range(1, 100));
			break;
		}
		cout << list[i]->calcArea() << endl;
		cout << list[i]->calcPerimeter() << endl << endl;
	}

	//Delete
	FOR(i, 30)
	{
		delete list[i];
		list[i] = NULL;
	}
	return 0;
}
