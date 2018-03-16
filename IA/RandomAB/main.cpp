/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Random(A, B)
 *
 *        Version:  1.0
 *        Created:  19.01.2017 16:49:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int rand01()
{
	return (double)rand()/RAND_MAX >= 0.5;
}

int Random(const int &s, const int &e)
{
	if(s == e)
		return s;

	double m = (s+e)/2;

	if(rand01() == 0)
		return Random(s, floor(m));
	else return Random(ceil(m), e);
}

int main()
{
	srand(time(0));

	int a, b;
	
	cout << "a, b: ";
	cin >> a >> b;

	cout << Random(a, b) << endl;
	return 0;
}

