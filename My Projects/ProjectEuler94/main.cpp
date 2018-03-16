/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Almost Equilateral triangles
 *
 *        Version:  1.0
 *        Created:  16.12.2016 12:50:18
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Leul Shiferaw (ls), l.shiferaw@jacobs-university.de
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <limits>
#include <cmath>
#include <stdio.h>

using namespace std;

bool is_int(const double &a)
{
	double int_part;
	return modf(a, &int_part);
}

double compute_area(const double &s, const int &a, const int &b, const int &c)
{
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
	int s = 2;
	long long pm = 0;
	double spm = 0;
	
	long ans = 0;
	while(true)
	{
		pm = s+s+s-1;
		if(pm > 1000000000)
			break;
		spm = pm/2.0;

		if(is_int(compute_area(spm, s, s, s-1)))
			ans += pm;

		pm = s+s+s;
		if(pm > 1000000000)
			break;
		spm = pm/2.0;

		if(is_int(compute_area(spm, s, s, s)))
			ans += pm;

		pm = s+s+s+1;
		if(pm > 1000000000)
			break;
		spm = pm/2.0;

		if(is_int(compute_area(spm, s, s, s+1)))
			ans+=pm;
		++s;
	}
	cout << ans << endl;
	return 0;
}
