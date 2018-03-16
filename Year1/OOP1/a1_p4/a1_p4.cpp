/*
	CH08-320142
	a1_p4.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include <string>

using namespace std;

int mycount(const int &x, const int &y)
{
	return y-x;
}

int mycount(const char &c, const string &s)
{
	int r = 0;

	for(unsigned int i = 0; i < s.size(); ++i)
		if(s[i]==c)
			++r;

	return r - (r==0);
}

int main()
{
	int x, y;
	char c;
	string s;

	cout << "Enter two integers: ";
	cin >> x >> y;

	cout << "Difference: " << mycount(x, y) << endl;

	cout << "Enter character: ";
	cin >> c;

	cout << "Enter string: ";
	cin >> s;

	cout << "Occurrence: " << mycount(c, s) << endl;

	return 0;
}