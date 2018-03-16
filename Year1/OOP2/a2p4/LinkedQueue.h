#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <cstddef>
#include <cassert>

template <class T>
struct Node
{
	T val;
	Node *next;
	Node *prev;	
};

template <class T>
class Queue
{
	private:
		int size;
		Node<T> *list;
		void destroy(Node<T> *);
	public:
		Queue();
		Queue(Queue&);
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
Queue<T>::Queue()
{
	list=NULL;
	size=0;
}

//Copy Constructor
template <class T>
Queue<T>::Queue(Queue & rhs):size(rhs.size)
{
	destroy(list);
	
	if(size!=0)
	{
		//First element
		list=new Node<T>;
		list.val=rhs.list->val;
		rhs.list=rhs.list->next;	

		Node<T> *cursor=list;	
		while(rhs.list!=NULL)
		{
			cursor->next=new Node<T>;
			cursor->next->val=rhs.list->val;
			rhs.list=rhs.list->next;
			cursor=cursor->next;
		}

		//Circular
		cursor->next=list;
		list->prev=cursor;
	}	
}

//Destroy List
template <class T>
void Queue<T>::destroy(Node<T> *ls)
{
	if(ls==NULL)
		return;
	destroy(ls->next);
	delete list;
	list=NULL;
}

//Destructor
template <class T>
Queue<T>::~Queue()
{
	destroy(list);
}

//Add element
template <class T>
bool Queue<T>::push(const T &ele)
{
	++size;
	if(size-1==0)
	{
		list=new Node<T>;
		list->val=ele;
		list->next=list;
		list->prev=list->next;
		return true;
	}

	Node<T> *tail=list->prev;
	list->prev=new Node<T>;
	list->prev->val=ele;
	list->prev->prev=tail;
	tail->next=list->prev;
	return true;
}

//Delete first element
template <class T>
bool Queue<T>::pop(T &out)
{
	if(size==0)
		return false;
	--size;
	out=list->val;
	if(size+1==1)
	{
		delete list;
		list=NULL;
		return true;
	}	
	
	//New tail and head
	Node<T> *tail=list->prev;
	Node<T> *head=list->next;

	delete list; //Pop
	
	//Assign new heads and tails
	list=head;
	list->prev=tail;
	tail->next=list;
	return true;
}

//Last element
template <class T>
T Queue<T>::back() const
{
	assert(size!=0);
	return list->prev->val;
}

//Front element
template <class T>
T Queue<T>::front() const
{
	assert(size!=0);
	return list->val;
}

//Number of elements
template <class T>
unsigned int Queue<T>::getNumEntries() const
{
	return size;
}

//Maxsize
//There is no max size(it is the memory)
template <class T>
unsigned int Queue<T>::getsize() const
{
	return size;
}

//Resize
template <class T>
void Queue<T>::resize(const int& n)
{
	if(size<=n)
		return;

	if(n==0)
	{
		size=0;
		destroy(list);
		return;
	}

	Node<T> *temp=NULL;
	Node<T> *tail=list->prev;//Get the tail

	//Go back from tail deleting elements until size=n
	int gap=size-n;		
	for(int i=0; i<gap; ++i)
	{
		temp=tail->prev;
		delete tail;
		tail=temp;	
	}

	size=n;
	tail->next=list;
	list->prev=tail;
}

#endif
