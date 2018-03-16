/*
 * JTSK-320413
 * a2_p1.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <iostream>
#include <cassert>
#include "Complex.h"

#define SIZE 10

using namespace std;

template <class T>
T array_min(T arr[], const int &n)
{
	assert(n>0);
	T smallest=arr[0];
	for(int i=1; i<n; ++i)
		if(arr[i]<smallest) smallest=arr[i];
	return smallest;	
}

int main()
{
	int A[SIZE];		
	
	for(int i=0; i<SIZE; ++i)
		A[i]=i;

	cout << array_min(A, SIZE) << endl;

	Complex *complexs=new Complex[SIZE];

	for(int i=0; i<10; ++i)
	{
		complexs[i].set_i(i);
		complexs[i].set_r(i);
	}

	cout << array_min(complexs, SIZE);
	delete[]complexs;
	return 0;
}
