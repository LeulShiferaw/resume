#include <time.h>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

float phi=1.61803398874989484;
cpp_int fib(int n)
{
	if(n==0||n==1)
		return 1;

	return fib(n-2) + fib(n-1);
}

cpp_int fib_lin(int n)
{
	cpp_int f1=0;
	cpp_int fn=1;

	int i;
	for(i=1; i<n; ++i)
	{
		fn+=f1;
		f1=fn-f1;
	}
	return fn;
}

cpp_int fib_inex(int n)
{
	float result=1;

	int i;
	for(i=0; i<n; ++i)
		result*=phi;
	return (long long)round(result/sqrt(5.0));
}

int main()
{
	int t=0,n=1;
	cpp_int fn=0;

	t=time(0);
	while(time(0)-t < 10)
	{
		++n;
		fib(n);	
	}

	cout << "N: " << n << endl;

	n=1;
	t=time(0);
	while(time(0)-t < 10)
	{
		++n;
		fib_lin(n);
	}

	cout << "N: " << n << endl;

	n=1;
	while(fib_inex(n)==fib_lin(n))
		++n;
	cout << "N: " << n << endl;

	return 0;
}
