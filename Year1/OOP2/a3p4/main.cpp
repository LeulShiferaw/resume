/*
 * JTSK-320143
 * a3_p4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <deque>
#include <iostream>

using namespace std;

int main()
{
	deque<double> A;

	double n;
	cin >> n;
	while(n!=0)
	{
		if(n<0)
			A.push_back(n);
		else A.push_front(n);
		cin >> n;
	}

	//Print A
	cout << "A: ";
	for(deque<double>::iterator itr=A.begin(); itr!=A.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	cout << endl;

	//Stop when switch from +ve to -ve
	deque<double>::iterator itr;
	for(itr=A.begin(); itr!=A.end();++itr)
	{
		if(*itr<0)
			break;
	}
	A.insert(itr,0);//Insert 0 at switch point

	//Print A with ;
	for(itr=A.begin(); itr!=A.end();)
	{
		cout << *itr;
		if(++itr!=A.end())
			cout << ";";
	}
	cout << endl;

	return 0;
}
