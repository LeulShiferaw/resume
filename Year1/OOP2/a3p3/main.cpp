/*
 * JTSK-320143
 * a3_p3.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */ 

#include <list>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
	list<int> A,B;//Two lists

	int n;	      //Input
	cin >> n;
	while(n>0)
	{
		A.push_front(n);
		B.push_back(n);
		cin >>n;
	}	

	//Print A
	cout << "A: ";
	for(list<int>::iterator itr=A.begin(); itr!=A.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	ofstream file("listB.txt");
	assert(file.is_open());

	//Print B in reverse
	cout << "B(reversed): ";
	for(list<int>::reverse_iterator itr=B.rbegin(); itr!=B.rend(); ++itr)
		file << *itr << " ";
	file << endl;	
	file.close();	

	cout << endl;

	//Move last elements to top
	A.push_front(A.back());
	B.push_front(B.back());
	A.pop_back();
	B.pop_back();

	//Print A
	cout << "A: ";
	for(list<int>::iterator itr=A.begin(); itr!=A.end();)
	{
		cout << *itr;
		if(++itr!=A.end())
			cout << ",";
	}	
	cout << endl;
	
	//Print B
	cout << "B: ";
	for(list<int>::iterator itr=B.begin(); itr!=B.end();)
	{
		cout << *itr;
		if(++itr!=B.end())
			cout << ",";
	}
	cout << endl;

	cout << endl;

	//Merge in a sorted order
	A.sort();
	B.sort();
	A.merge(B);

	//Print merged list
	cout << "Merged: ";
	for(list<int>::iterator itr=A.begin(); itr!=A.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	return 0;
}
