/*
	CH08-320142
	a2_p3.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>

using namespace std;

//for loop shorthand
#define FOR(i, j) for(i = 0; i<j; ++i)

void subtract_max(int* &A, const int &n)
{
	int i, max = A[0];

	//Find max
	FOR(i, n)
		if(A[i]>max) max = A[i];

	FOR(i, n)
		A[i] -= max;
}

int main()
{
	int i, n;
	cout << "n: ";
	cin >> n;

	int *A = new int[n];

	FOR(i, n)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}

	cout << endl;

	subtract_max(A, n);

	//Display
	FOR(i, n) cout << A[i] << " ";
	cout << endl;

	delete []A;
	A = NULL;
	return 0;
}