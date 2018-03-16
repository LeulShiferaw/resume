/*
	CH08-320142
	a6_p1.cpp
	Leul Shiferaw
	l.shiferaw@jacbos-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

#define UNTIL(n) for(int _i = 0; _i < n; ++_i)

int rand_number(const int & l, const int &h)
{
	return rand() % (h-l+1) + l;
}

string rand_color(string colors[], const int &n)
{
	return colors[rand_number(0, n-1)];
}

int main()
{
	srand(time(0));

	string colors[] = {"RED", "BLACK", "VIOLET", "BLUE"};

	UNTIL(12)
		cout << rand_color(colors, 4) << endl;
	return 0;
}