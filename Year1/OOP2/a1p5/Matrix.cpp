#include "Matrix.h"
#include <cassert>

//Constructor
Matrix::Matrix(const int& a, const int& b):n(a),m(b)
{
	grid=new int*[a];
	for(int i=0; i<a;++i)
		grid[i]=new int[b];	
}

//Destructor
Matrix::~Matrix()
{
	for(int i=0; i<n; ++i)
	{
		delete[]grid[i];
		grid[i]=NULL;
	}
	delete[]grid;
	grid=NULL;
}

//Matrix + Matrix
Matrix Matrix::operator+(const Matrix& rhs) const
{
	assert(this->n==rhs.n && this->m==rhs.m);

	Matrix res(n,m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			res.grid[i][j]=grid[i][j]+rhs.grid[i][j];
	return res;
}

//Matrix - Matrix
Matrix Matrix::operator-(const Matrix& rhs) const
{
	assert(this->n==rhs.n && this->m==rhs.m);

	Matrix res(n,m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			res.grid[i][j]=grid[i][j]-rhs.grid[i][j];
	return res;
}

//Matrix * Vector
Vector<int> Matrix::operator*(const Vector<int> &rhs) const
{
	//(nx1)x(1xp)
	assert(m!=1); //This returns a Matrix

	//(nxm)x(mx1)
	assert(this->m==rhs.get_size());

	Vector<int> res(this->n);
	for(int i=0; i<n; ++i)
	{
		int dot_pro=0;
		for(int j=0; j<m; ++j)
			dot_pro+=grid[i][j]*rhs.get(j);
		res.set(i, dot_pro);
	}

	return res;
}

//Vector * Matrix
Vector<int> operator*(const Vector<int> &vec, const Matrix& mat)
{
	//(px1)x(1xm)
	assert(mat.n!=1);	
	
	//(1xp)x(nxm)
	assert(vec.get_size()==mat.n);

	Vector<int> res(mat.m);

	for(int i=0; i<mat.m; ++i)
	{
		int dot_pro=0;
		for(int j=0; j<mat.n; ++j)
			dot_pro+=vec.get(j)*mat.grid[j][i];
		res.set(i, dot_pro);
	}

	return res;
}

//Matrix * Matrix
Matrix Matrix::operator*(const Matrix &rhs) const
{
	assert(this->m==rhs.n);

	Matrix res(this->n,rhs.m);
	for(int i=0; i<res.n; ++i)
	{
		for(int j=0; j<res.m; ++j)
		{
			int dot_pro=0;
			for(int k=0; k<rhs.n; ++k)
				dot_pro+=this->grid[i][k]*rhs.grid[k][j];
			res.grid[i][j]=dot_pro;
		}
	}

	return res;
}

std::ostream& operator<<(std::ostream& out, const Matrix &mat)
{
	for(int i=0; i<mat.n; ++i)
	{
		for(int j=0; j<mat.m; ++j)
			out << mat.grid[i][j] << " ";
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& ins, const Matrix &mat)
{
	for(int i=0; i<mat.n; ++i)
		for(int j=0; j<mat.m; ++j)
			ins >> mat.grid[i][j];
	return ins;
}
