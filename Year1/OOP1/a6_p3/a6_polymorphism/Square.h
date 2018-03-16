#include "Rectangle.h"

class Square : public Rectangle
{
public:
	Square(const char *, const double &);
	~Square();
	double calcArea() const;
	double calcPerimeter() const;
};