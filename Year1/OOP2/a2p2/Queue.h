#ifndef QUEUE_H
#define QUEUE_h

#include <cstddef>
#include <cassert>

template <class T>
class Queue
{
	private:
		unsigned int beg;
		unsigned int end;
		unsigned int max_size;
		T *elements;
	public:
		Queue();
		Queue(const int &);
		Queue(const Queue &);
		~Queue();

		bool push(const T&);
		bool pop(T&);
		T back() const;
		T front() const;
		unsigned int getNumEntries() const;
};

//Default Constructor
template <class T>
Queue<T>::Queue():beg(0),end(0),max_size(10)
{
	elements=new T[10];
	assert(elements!=NULL);
}

//Parametric Constructor -1
template <class T>
Queue<T>::Queue(const int &n):beg(0),end(0),max_size(n)
{
	elements=NULL;
	if(n)
	{
		elements=new T[n];
		assert(elements!=NULL);
	}
}

//Copy Constructor
template <class T>
Queue<T>::Queue(const Queue &rhs):beg(rhs.beg),end(rhs.end),max_size(rhs.max_size)
{
	elements=NULL;
	elements=new T[max_size];
	assert(elements!=NULL);	
}

//Destructor
template <class T>
Queue<T>::~Queue()
{
	if(max_size)
		delete[]elements;
	elements=NULL;
}

//Add element
template <class T>
bool Queue<T>::push(const T &ele)
{
	if(getNumEntries()==max_size)
		return false;

	elements[end]=ele;
	++end;
	return true;
}

//Delete first element
template <class T>
bool Queue<T>::pop(T &out)
{
	if(getNumEntries()==0)
		return false;
	out=elements[beg];
	beg=(beg+1)%max_size;	
	return true;
}

//Last element
template <class T>
T Queue<T>::back() const
{
	assert(getNumEntries()!=0);
	return elements[end-1];
}

//Front element
template <class T>
T Queue<T>::front() const
{
	assert(getNumEntries()!=0);
	return elements[beg];
}

//Number of elements
template <class T>
unsigned int Queue<T>::getNumEntries() const
{
	return end-beg;
}
#endif
