//This program should print 0 to 10 in order
#include <iostream>
#include "queue.hpp"

int main()
{
	Queue<int> queue;

	for(int i=0; i<10; ++i)
		queue.enqueue(i);

	while(!queue.is_empty())
		cout << queue.dequeue() << " ";
	cout << endl;

	return 0;
}
