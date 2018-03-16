#ifndef PQUE_H
#define PQUE_H

#include "heap.h"

template <class T>
class Pqueue
{
	private:
		Heap<T> *elements;				
	public:
		Pqueue(const int&);	
		~Pqueue();
		void enqueue(const T&);
		T dequeue();
};
#endif
