/*
	CH08-320142
	a1_p2.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	double x;
	string s;

	cout << "n: ";
	cin >> n;

	cout << "x: ";
	cin >> x;

	cout << "s: ";
	cin >> s;

	cout << endl;

	for(int i = 0; i<n; ++i)
		cout << s << ":" << x << endl;

	return 0;
}