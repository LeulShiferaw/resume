/*
 * JTSK-320143
 * a1_p5.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-universiy.de
 */
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix matA(1,2);	
	Vector<int> vecA(2);
	
	cin >> matA;
	cin >> vecA;
	cout << (vecA*matA);
	return 0;
}
