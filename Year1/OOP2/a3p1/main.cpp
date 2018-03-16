/*
 * JTSK-320143
 * a3_p1.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<string> vec;
	
	string str;
	while(true)
	{
		cin >> str;
		if(str=="stop")
			break;
		vec.push_back(str);
	}	

	int n=vec.size();
	for(int i=0; i<n; ++i)
	{
		cout << vec[i];
		if(i!=n-1)
			cout << ",";
	}
	cout << endl;

	for(vector<string>::iterator it=vec.begin(); it!=vec.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
