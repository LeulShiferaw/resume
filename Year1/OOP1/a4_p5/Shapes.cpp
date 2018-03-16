// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"

using namespace std; 

Shape::Shape():name("No Name"){}

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

Shape::Shape(const Shape &rhs)
{
	name = rhs.name;
}

CenteredShape::CenteredShape(): x(0), y(0){}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon(): EdgesNumber(0){} 

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

RegularPolygon::RegularPolygon(const RegularPolygon &rhs)
:CenteredShape(rhs.name, rhs.x, rhs.y)
{
	EdgesNumber = rhs.EdgesNumber;
}

Circle::Circle():Radius(0){}

Circle::Circle(const string& n, double nx, double ny, double r) : 
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}

Circle::Circle(const Circle &rhs)
:CenteredShape(rhs.name, rhs.x, rhs.y)
{
	Radius = rhs.Radius;
}

double Circle::perimeter()
{
	return 2*PI*Radius;
}

double Circle::area()
{
	return PI*Radius*Radius;
}

Rectangle::Rectangle():w(0), h(0){}

Rectangle::Rectangle(const string &n, double nx, double ny, const double &w, const double &h)
: RegularPolygon(n, nx, ny, 4)
{
	this->w = w;
	this->h = h;
}

Rectangle::Rectangle(const Rectangle &rhs)
:RegularPolygon(rhs.name, rhs.x, rhs.y, 4)
{
	w = rhs.w;
	h = rhs.h;
}

double Rectangle::perimeter()
{
	return 2*(w+h);
}

double Rectangle::area()
{
	return w*h;
}

Square::Square():s(0){}

Square::Square(const string &n, double nx, double ny, const double &s)
: Rectangle(n, nx, ny, s, s)
{
	this->s = s;
}

Square::Square(const Square &rhs)
: Rectangle(rhs.name, rhs.x, rhs.y, rhs.s, rhs.s)
{
	s = rhs.s;
}