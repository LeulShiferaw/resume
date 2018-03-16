#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

class Matrix
{
	private:
		int n,m;
		int **grid;
	public:
		Matrix(const int&,const int&);
		~Matrix();	
		
		//Operators
		Matrix operator+(const Matrix&) const;
		Matrix operator-(const Matrix&) const;
		Matrix operator*(const Matrix&) const;
		Vector<int> operator*(const Vector<int>&)const;
		friend Vector<int> operator*(const Vector<int>&,const Matrix&);
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		friend std::istream& operator>>(std::istream&, const Matrix&);	
};
#endif
