#include "Vector.h"
#include <cassert>
#include <cstddef>
#include <math.h>

//Constructor
template <class T>
Vector<T>::Vector():size(0),elements(NULL){}

//Construct vector of size n
template <class T>
Vector<T>::Vector(const int& n)
{
	size=n;
	elements=new T[n];
	assert(elements!=NULL);
}

//Copy rhs to current vector
template <class T>
Vector<T>::Vector(const Vector& rhs)
{
	if(size) delete[]elements;

	elements=new T[rhs.size];
	for(int i=0; i<rhs.size; ++i)
		elements[i]=rhs.elements[i];
}

//Destroy current vector
template <class T>
Vector<T>::~Vector()
{
	if(size) delete[]elements;
	elements=NULL;
}

//Set the ith value
template <class T>
void Vector<T>::set(const int& i, const T& v)
{
	assert(i<size);
	elements[i]=v;
}

//Get the ith value
template <class T>
T Vector<T>::get(const int& i) const
{
	assert(i<size);
	return elements[i];
}

//Reset the size of the vector
template <class T>
void Vector<T>::set_size(const int& n)
{
	if(size) delete[]elements;

	size=n;
	elements=new T[n];
	assert(elements!=NULL);
}

//Calc and return the magnitude of the vector
template <class T>
double Vector<T>::norm() const
{
	double mag=0;
	for(int i=0; i<size; ++i)
		mag+=elements[i]*elements[i];
	return sqrt(mag);
}

//Add two vectors
template <class T>
Vector<T> Vector<T>::operator+(const Vector& rhs) const
{
	assert(size==rhs.size);

	Vector<T> res(size);
	for(int i=0; i<size;++i)
		res.elements[i]=this->elements[i]+rhs.elements[i];
	return res;
}

//Subtract
template <class T>
Vector<T> Vector<T>::operator-(const Vector& rhs) const
{
	assert(size==rhs.size);

	Vector<T> res(size);
	for(int i=0; i<size;++i)
		res.elements[i]=this->elements[i]-rhs.elements[i];
	return res;
}

//Dot product
template <class T>
double Vector<T>::operator*(const Vector& rhs) const
{
	assert(size==rhs.size);

	double dot=0;
	for(int i=0; i<size; ++i)
		dot+=elements[i]*rhs.elements[i];
	return dot;
}

std::ostream& operator<<(std::ostream& out, const Vector<int> &vec)
{
	for(int i=0; i<vec.size;++i)
		out << vec.elements[i] << " ";
	out << std::endl;
	return out;
}

std::istream& operator>>(std::istream& ins, const Vector<int> &vec)
{
	for(int i=0; i<vec.size; ++i)
		ins >> vec.elements[i];
	return ins;
}

template class Vector<int>;
