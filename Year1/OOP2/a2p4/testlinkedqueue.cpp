/*
 * JTSK-320143
 * a2_p4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include "LinkedQueue.h"
#include <iostream>

using namespace std;

int main()
{
	Queue<int> my_que;//Initial size = 10

	for(int i=0; i<100; ++i) //Push 100 b/c of resize
		my_que.push(i);
	
	int val;
	for(int i=0; i<100; ++i)
	{
		if(my_que.pop(val))
			cout << val << " ";
	}
	cout << endl;
	return 0;
}
