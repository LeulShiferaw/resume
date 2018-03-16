#include "pque.h"
#include <cstddef>
#include <cassert>

template <class T>
Pqueue<T>::Pqueue(const int& n)
{
	elements=new Heap<T>(n);
	assert(elements!=NULL);
}

template <class T>
Pqueue<T>::~Pqueue()
{
	delete elements;
	elements=NULL;
}

template <class T>
void Pqueue<T>::enqueue(const T& v)
{
	elements->insert(v);
}

template <class T>
T Pqueue<T>::dequeue()
{
	return elements->extract();
}

template class Pqueue<int>;
