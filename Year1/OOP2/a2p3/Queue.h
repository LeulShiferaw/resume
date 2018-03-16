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
		T min(const T& v1,const T& v2) const{if(v1<v2) return v1; else return v2;}
	public:
		Queue();
		Queue(const int &);
		Queue(const Queue &);
		~Queue();

		T back() const;
		T front() const;
		bool pop(T&);
		bool push(const T&);
		void resize(const int&);
		unsigned int getsize() const;
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
		resize(getNumEntries()+10);

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

//Maxsize
template <class T>
unsigned int Queue<T>::getsize() const
{
	return max_size;
}

//Extend
template <class T>
void Queue<T>::resize(const int& n)
{
	max_size=n;

	//Resize to nothing
	if(!n)
	{
		delete[]elements;
		elements=NULL;
		return;
	}

	//Create new array
	T *new_elements= new T[n];
	assert(new_elements!=NULL);

	//Copy previous array
	int s=min(getNumEntries(),n);
	for(int i=0; i<s; ++i)
		new_elements[i]=elements[i];

	//Delete old array and reassign
	delete[]elements;
	elements=new_elements;
	new_elements=NULL;
}
#endif
