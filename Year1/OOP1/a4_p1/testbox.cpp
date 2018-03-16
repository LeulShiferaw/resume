/*
	CH08-320142
	a4_p1.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include "Box.h"

#define FOR(i, n) for(; i < n; ++i)
#define CHECK_ERROR(A) if(A == NULL) { cout << "Error Allocating Memory" << endl; return 0; } 

using namespace std;

int main()
{
	int n;

	cout << "n: ";
	cin >> n;

	Box **boxes = new Box*[n*2];
	CHECK_ERROR(boxes);
	
	//First Half of the boxes
	double l, w, h;
	for(int i = 0; i<n; ++i)
	{
		cout << "Box[" << i << "]: ";
		cin >> l >> w >> h;

		boxes[i] = new Box(l, w, h);
	}
	
	//Second Half	
	for(int i = n; i<2*n; ++i)
	{
		boxes[i] = new Box(*boxes[i-n]); //Copy constructor
		CHECK_ERROR(boxes[i]);	
	}
	for(int i = 0; i<2*n; ++i)
	{
		boxes[i]->print();
		boxes[i]->print_vol();
	}

	for(int i = 0; i<2*n; ++i)
	{
		delete boxes[i];
		boxes[i] = NULL;
	}

	delete []boxes;
	boxes = NULL;

	return 0;
}
