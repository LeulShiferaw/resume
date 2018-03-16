#include "heap.h"
#include <cassert>
#include <cstddef>

template <class T>
Heap<T>::Heap(const int& n):size(0), max_size(n)
{
	elements=new T[n];
	assert(elements!=NULL);
}

template <class T>
Heap<T>::~Heap()
{
	delete []elements;
}

template <class T>
void Heap<T>::insert(const T& v)
{
	if(size==max_size)
		throw "Overflow\n";
	elements[size]=v;	
	++size;
	fix_heap_bot();
}

template <class T>
T Heap<T>::extract()
{
	if(size==0)
		throw "Underflow\n";

	T largest=elements[0];//Save largest, it is always on top since max heap

	//Swap with last element
	swap(elements[0],elements[size-1]);
	--size;//Remove last element
	fix_heap_top();//Fix heap

	return largest;
}

template <class T>
T Heap<T>::find()
{
	if(size==0)
		throw "Underflow\n";
	return elements[0];
}

template <class T>
void Heap<T>::swap(T &v1, T &v2)
{
	T temp=v1;
	v1=v2;
	v2=temp;
}

template <class T>
void Heap<T>::fix_heap_bot()
{
	int par=0;
	int pos=size-1;
	while(pos>0)
	{
		par=(pos-(1-pos%2))/2;
		if(elements[par]<elements[pos])
			swap(elements[par], elements[pos]);
		else break;
		pos=par;
	}
}

template <class T>
void Heap<T>::fix_heap_top()
{
	int pos=0;
	int child1=1,child2=2;
	while(child1<size)
	{
		if(child2>=size)
		{
			if(elements[child1]>elements[pos])
				swap(elements[child1],elements[pos]);
			return;
		}		
		else if(elements[child1]>elements[child2])
		{
			if(elements[child1]>elements[pos])
				swap(elements[child1],elements[pos]);
			else return;
			pos=child1;
		}
		else if(elements[child2]>elements[pos])
		{
			swap(elements[child2],elements[pos]);
			pos=child2;
		}
		child1=2*pos+1;
		child2=child1+1;
	}
}

template class Heap<int>;//Only use heaps with ints
