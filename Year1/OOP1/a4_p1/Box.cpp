#include "Box.h"

void Box::setl(const double &x){l = x;}
void Box::setw(const double &x){w = x;}
void Box::seth(const double &x){h = x;}

Box::Box(const Box &b){l = b.l; w = b.w; h = b.h;}

void Box::print() const
{
	std::cout << "L: " << l << ", W: " << w << ", H: " << h << std::endl;
}

void Box::print_vol() const
{
	std::cout << "Vol: " << l*w*h << std::endl;
}