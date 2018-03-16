/*
 * Algo and DS
 * a6_4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include "buffer.hpp"
#include <iostream>

using namespace std;

int main()
{

	try
	{
		int n;
		cin >> n;//If n is < 10 then it will be overflow

		Buffer<int> my_buf(n);
		for(int i=0; i<10; ++i)
			my_buf.enqueue(i);
		for(int i=0; i<10; ++i)
			cout << my_buf.dequeue() << " ";
		cout << endl;
	}
	catch(const char* &s)
	{
		cout  << s << endl;
		return 1;
	}

	return 0;
}
