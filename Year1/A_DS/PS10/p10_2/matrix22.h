#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

class Matrix22
{
	private:
		cpp_int grid[2][2];
	public:
		Matrix22(const cpp_int[][2]);		
		cpp_int get(const int&,const int&)const;
};

Matrix22::Matrix22(const cpp_int input[][2])
{
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
			grid[i][j]=input[i][j];
}

cpp_int Matrix22::get(const int &i, const int &j) const
{
	return grid[i][j];
}

template <class T>
class Monoid
{
	public:
		virtual T e()=0;
		virtual T op(const T&,const T&)=0;
};

template <class T> T Monoid<T>::e()
{
	Matrix22 res({{1,0},{0,1}});
	return res;
}

class Matrix22Multiplication : public Monoid<Matrix22>
{
	public:
		Matrix22 e();
		Matrix22 op(const Matrix22&,const Matrix22&);
};

Matrix22 Matrix22Multiplication::e()
{
	cpp_int temp[][2]={{1,0},{0,1}};
	Matrix22 res(temp);
	return res;
}

Matrix22 Matrix22Multiplication::op(const Matrix22 &m1, const Matrix22 &m2)
{
	cpp_int temp[][2]={{m1.get(0,0)*m2.get(0,0)+m1.get(0,1)*m2.get(1,0), m1.get(0,0)*m2.get(0,1)+m1.get(0,1)*m2.get(1,1)},{m1.get(1,0)*m2.get(0,0)+m1.get(1,1)*m2.get(1,0),m1.get(1,0)*m2.get(0,1)+m1.get(1,1)*m2.get(1,1)}};
	Matrix22 res(temp);
	return res;
}


