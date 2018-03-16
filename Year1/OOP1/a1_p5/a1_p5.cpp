/*
	CH08-320142
	a1_p5.cpp
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool exit = false;
	string s, r = "";
	while(!exit)
	{
		cout << "Enter string: ";
		cin >> s;

		if(s=="quit")
		{
			exit = true;
			continue;
		}

		r+=s;
	}

	cout << "Result: " << r << endl;
	return 0;
}