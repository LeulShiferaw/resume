/*
 * JTSK-320143
 * a3_p2.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string in="";		//Input
	vector<string> vec;	//Vector to store input

	getline(cin,in,'\n');
	while(in!="STOP")
	{
		vec.push_back(in);//Add to vector
		getline(cin,in,'\n');
	}

	//If second and fourth element exist; swap
	if(vec.size()>3)
		swap(vec[1],vec[3]);
	else cerr << "No 2nd element or no 4th element\n";

	//Replace last element with "?"
	vec.back()="?";

	//Print elements separated with commas
	for(unsigned int i=0; i<vec.size(); ++i)
	{
		cout << vec[i];
		if(i!=vec.size()-1) cout << ",";
	}
	cout << endl;

	//Print elements separated with -
	for(vector<string>::iterator itr=vec.begin(); itr!=vec.end(); ++itr)
	{
		cout << *itr;
		if(itr!=vec.end()-1) cout << "-";
	}
	cout << endl;

	//Print elements in reverse separated with a space
	for(vector<string>::iterator itr=vec.end()-1; itr!=vec.begin()-1;--itr)
	{
		cout << *itr;
		if(itr!=vec.begin()) cout << " ";	
	}
	cout << endl;
	return 0;
}
