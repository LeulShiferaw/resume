/*
 * JTSK-320143
 * a4_p4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <map>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

typedef map<int,pair<string,string> > mipss;
int main()
{
	ifstream file("data.txt");
	assert(file.is_open());

	int mat;			//Matriculation number
	mipss data;			//Store data
	pair<string,string> name;	//First and second name
	while(file >> mat)
	{
		file >> name.first >> name.second; //Read data
		data[mat]=name;			   //Save data
	}

	mipss::iterator it;
	while(true)
	{
		cout << "Matriculation Number: ";
		cin >> mat;
		
		it=data.find(mat);//Find data
		if(it==data.end())//If not found print error
			cerr << "Matriculation number not found!\n";
		else cout << "Name: " << it->second.first << " " << it->second.second << endl;
	}
	file.close();
	return 0;
}
