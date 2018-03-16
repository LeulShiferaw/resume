/*
 * JTSK-321043
 * a4_p3.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	set<int> A;
	multiset<int> B;

	int n=0;
	while(true)
	{
		cin >> n;
		if(n<0)
			break;
		A.insert(n);
		B.insert(n);
	}

	cout << "A: ";
	for(set<int>::iterator it=A.begin(); it!=A.end(); ++it)
		cout << *it << " ";
	cout << endl << endl;

	cout << "B: ";
	for(set<int>::iterator it=B.begin(); it!=B.end(); ++it)
		cout << *it << " ";
	cout << endl << endl;

	A.erase(7);
	B.erase(7);

	cout << "A: ";
	for(set<int>::iterator it=A.begin(); it!=A.end(); ++it)
		cout << *it << " ";
	cout << endl << endl;

	cout << "B: ";
	for(set<int>::iterator it=B.begin(); it!=B.end(); ++it)
		cout << *it << " ";
	cout << endl << endl;

	A.insert(15);
	A.insert(121);

	set<int> set_temp;
	multiset<int> temp;
	set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(temp,temp.begin()));

	cout << "AUB ";
	for(set<int>::iterator it=temp.begin(); it!=temp.end(); ++it)
		cout << *it << " ";
	cout << endl;

	temp.clear();

	set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(temp,temp.begin()));

	cout << "AnB: ";
	for(set<int>::iterator it=temp.begin(); it!=temp.end(); ++it)
		cout << *it << " ";
	cout << endl;

	temp.clear();
	set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(set_temp,set_temp.begin()));

	cout << "A/B: ";
	for(set<int>::iterator it=set_temp.begin(); it!=set_temp.end(); ++it)
		cout << *it << " ";
	cout << endl;

	set_temp.clear();
	set_symmetric_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(set_temp,set_temp.begin()));

	cout << "A/B U B/A: ";
	for(set<int>::iterator it=set_temp.begin(); it!=set_temp.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
