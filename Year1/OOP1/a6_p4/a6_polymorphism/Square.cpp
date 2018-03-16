#include "Square.h"
#include <iostream>

Square::Square(const char *n, const double &s)
: Area(n), Rectangle(n, s, s)
{
}

Square::~Square()
{}

double Square::calcArea() const
{
	std::cout << "calcArea of Square... ";
	return Rectangle::calcArea();
}

double Square::calcPerimeter() const
{
	std::cout << "calcPerimeter of Square... ";
	return Rectangle::calcPerimeter();
}