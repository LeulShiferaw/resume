#include <iostream>
#include "matrix22.h"

using namespace std;

template <class T>
Matrix22 sqmult(const Monoid<T> &bin_fun,const Matrix22 &F, const int &n)
{
	if(n==0)
		return bin_fun.e();
	Matrix22 temp=sqmult(bin_fun,F,n/2);
	temp=bin_fun.op(temp,temp);
	if(n%2) temp=bin_fun.op(F,temp);
	return temp;
}

void display(const Matrix22 &grid)
{
	for(int i=0; i<2; ++i)
	{
		for(int j=0; j<2; ++j)
			cout << grid.get(i,j) << " ";
		cout << endl;
	}
}

int main()
{
	int n;

	cpp_int temp[][2]={{1,1},{1,0}};
	Matrix22 F(temp);
	while(true)
	{
		cin >> n;
		cout << "Fib(" << n << "): ";
		if(n<=0)
			cout << 0 << endl;
		else cout << sqmult(Matrix22Multiplication(),F,n-1).get(0,0) << endl;
	}

	return 0;
}
