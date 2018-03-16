#ifndef HEAP_H
#define HEAP_H
template <class T>
class Heap
{
	private:
		int size;
		int max_size;
		T *elements;
		void swap(T&,T&);
	public:
		Heap(const int&);
		~Heap();
		void insert(const T&);
		T extract();
	        T find();		
		void fix_heap_bot();
		void fix_heap_top();
};

#endif
