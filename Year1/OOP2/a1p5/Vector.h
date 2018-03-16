#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class T>
class Vector
{
	private:
		int size;
		T *elements;
	public:
		Vector();
		Vector(const int&);
		Vector(const Vector&);//Copy constructor
		~Vector();
		
		//Setters
		void set(const int&,const T&);
		T get(const int&) const;
		int get_size() const {return size;}
		void set_size(const int&);//set size

		double norm() const;

		//Operators
		Vector<T> operator+(const Vector&) const;
		Vector<T> operator-(const Vector&) const;
		double operator*(const Vector&) const;	
		friend std::istream& operator>>(std::istream&, const Vector<int>&);

		friend std::ostream& operator<<(std::ostream&, const Vector<int>&);
};
#endif
