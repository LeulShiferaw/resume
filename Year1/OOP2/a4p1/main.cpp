/*
 * JTSK-320143
 * a4_p1.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<char> alpha;

	for(int i=0; i<26; ++i)
		alpha.push_back('a'+i);

	reverse(alpha.begin(), alpha.end());

	for(vector<char>::iterator it=alpha.begin(); it!=alpha.end(); ++it)
		cout << *it << " ";
	cout << endl;

	alpha.push_back('f');

	replace(alpha.begin(),alpha.end(),'f','$');

	for(vector<char>::iterator it=alpha.begin(); it!=alpha.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
