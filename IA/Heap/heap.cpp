#include "heap.h"
#include <cstddef>

Heap::Heap(int *ele, int n)
:size(n)
{
	A=new int[n];
	for(int i=0; i<n; ++i)
		A[i]=ele[i];
}

Heap::~Heap()
{
	delete[]A;
	A=NULL;
}

void Heap::max_heapify(int i)
{
	int l,r;
	int largest;

	if(i>=size) return;
	while(true)
	{
		l=left(i);
		r=right(i);

		if(l<size && A[l]>A[i])
			largest=l;
		else largest=i;
		if(r<size && A[r]>A[largest])
			largest=r;

		if(largest==i) break;

		//Swap
		int temp=A[largest];
		A[largest]=A[i];
		A[i]=temp;

		i=largest;
	}
}

void Heap::min_heapify(int i)
{
	int l,r;
	int smallest;

	if(i>=size) return;
	while(true)
	{
		l=left(i);
		r=right(i);

		if(l<size && A[l]<A[i])
			smallest=l;
		else smallest=i;
		if(r<size && A[r]<A[smallest])
			smallest=r;

		if(smallest==i) break;

		//Swap
		int temp=A[smallest];
		A[smallest]=A[i];
		A[i]=temp;

		i=smallest;
	}
}

void Heap::build_max_heapify()
{
	for(int i=(size/2)-1; i>=0; --i)
		max_heapify(i);
}

//Build min heapify
void Heap::build_min_heapify()
{
	for(int i=(size/2)-1; i>=0; --i)
		min_heapify(i);
}

void Heap::sort()
{
	build_max_heapify();
	int t_size=size;
	for(int i=size-1; i>=0; --i)
	{
		//Swap with first element
		int temp=A[0];
		A[0]=A[i];
		A[i]=temp;		

		--size;
		max_heapify(0);
	}
	size=t_size;
}

void Heap::display()const
{
	for(int i=0; i<size; ++i)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}
