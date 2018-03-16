/*
 * JTSK-320143
 * a5_p1.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	try
	{
		//Store '@' 15 times in chars
		vector<char> chars;
		for(int i=0; i<15; ++i)
		{
			chars.push_back('@');
		}
		//Acces 16th element
		cout << chars.at(20);
	}
	catch(const out_of_range &oor)
	{
		cerr << "Out of range error: " << oor.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << "Uncaught exception!\n";
		return 1;
	}
	return 0;
}
