#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pque.h"

using namespace std;

int rand_range(const int &l, const int &h)
{
	return rand()%(h-l+1)+l;
}

int main()
{
	srand(time(0));
	
	int randm=0;
	const int n=10;
	Pqueue<int> my_pque(n);
	for(int i=0; i<n; ++i)
	{
		randm=rand_range(1,100);
		my_pque.enqueue(randm);
		cout << randm << " ";
	}	
	cout << endl;

	for(int i=0; i<n; ++i)
		cout << my_pque.dequeue() << " ";
	cout << endl;

	return 0;	
}
