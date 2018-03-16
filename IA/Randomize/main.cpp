/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Randomly permute an array
 *
 *        Version:  1.0
 *        Created:  17.01.2017 10:08:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rand_range(const int &l, const int &h)
{
	return rand()%(h-l+1) + l;
}

void swap(int A[], const int &i, const int &j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Randomize(int A[], const int &n)
{
	for(int i = 0; i<n; ++i)
		swap(A, i, rand_range(i, n-1));
}

void display(int A[], const int &n)
{
	for(int i = 0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(0));

	int n;
	cout << "n: ";
	cin >> n;

	int A[n];
	for(int i = 0; i<n; ++i)
		A[i] = i+1;

	Randomize(A, n);

	display(A, n);
	
	return 0;
}

