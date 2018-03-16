// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"

using namespace std;

Shape::Shape():name("None"){}

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape():x(0), y(0){}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon():EdgesNumber(6){}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny)
{
	EdgesNumber = nl;
}

Circle::Circle(const string& n, double nx, double ny, double r) :
  CenteredShape(n,nx,ny)
{
	Radius = r;
}

Hexagon::Hexagon(const string &sn, double ox, double oy, int en, const int &s, const string &c) :
  RegularPolygon(sn, ox, oy, en)
{
	side = s;
	color = c;
}

Hexagon::Hexagon(const Hexagon& rhs)
 {
 	side = rhs.side;
 	color = rhs.color;
 }

int Hexagon::perimeter()
{
	return 6*side;
}

double Hexagon::area()
{
	return (3.0/2)*sqrt(3)*side*side;
}
