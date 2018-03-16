#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap
{
	private:
		int *A;		
		int size;
	public:
		Heap(int*,int);
		~Heap();

		int parent(int i)const{return i/2;}
		int left(int i)const{return 2*i+1;}
		int right(int i)const{return 2*i+2;}

		void max_heapify(int);
		void min_heapify(int);
		void build_max_heapify();
		void build_min_heapify();
		void sort();
		void display()const;
};
#endif
