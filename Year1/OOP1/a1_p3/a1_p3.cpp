/*
	CH08-320142
	a1_p3.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>

using namespace std;

float abs(float &f)
{
	f < 0 ? f *= -1 : f;
	return f;
}

int main()
{
	float f;

	cout << "Enter float: ";
	cin >> f;

	cout << "Result: " << abs(f) << endl;
	return 0;
}