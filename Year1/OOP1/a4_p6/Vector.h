#include "Vector.h"
#include <iostream>
#include <math.h>

using namespace std;

Vector::Vector() : s(0), elements(NULL){}

Vector::Vector(const int &si)
{
	s = si;
	elements = new double[si];
}

Vector::Vector(const Vector &rhs)
{
	s = rhs.s;
	if(s > 0)
	{
		elements = new double[s];
		for(int i = 0; i < s; ++i)
			elements[i] = rhs.get(i);
	}
}

Vector::~Vector()
{
	if(s)
		delete[] elements;
	s = 0;
	elements = NULL;
}

void Vector::set_s(const int &x)
{
	if(s != 0)
		delete[] elements;
	if(x!=0)
		elements = new double[x];
	s = x;
}

void Vector::print() const
{
	for(int i = 0; i < s; ++i)
		cout << elements[i] << " ";
	cout << endl;
}

double Vector::norm() const
{
	double r = 0;
	for(int i = 0; i < s; ++i)
		r+=elements[i]*elements[i];
	return sqrt(r);
}

Vector Vector::add(const Vector &rhs) const
{
	Vector vec(s);

	for(int i = 0; i < s; ++i)
		vec.set(i, get(i) + rhs.get(i));

	return vec;
}

Vector Vector::diff(const Vector &rhs) const
{
	Vector vec(s);

	for(int i = 0; i < s; ++i)
		vec.set(i, get(i) - rhs.get(i));

	return vec;
}

double Vector::dot(const Vector &rhs) const
{
	double r = 0;

	for(int i = 0; i < s; ++i)
		r += get(i) * rhs.get(i);

	return r;
}