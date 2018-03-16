#ifndef LIST_H
#define LIST_H

#include <queue>
#include <cstddef>

/*----ITERATOR CLASS--- */
template <class T>
class Iterator
{
	public:
		virtual T next()=0;
		virtual T value()=0;//Current value
		virtual bool has_next()=0;
};
/*----END ITERATOR CLASS---- */

/*----SET CLASS----*/
template <class T>
class Set
{
	public:
		virtual void insert(const T&)=0;
		virtual void remove(const T&)=0;
		virtual bool contains(const T&)=0;
};
/*----END SET CLASS---- */

/*----LIST STRUCTURE--- */
template <class T>
struct Node
{
	T val;
	Node *next;
};
/*----END LIST STRUCTURE--- */



/*----LIST SET CLASS----*/
template <class T>
class ListSet : public Set<T>
{
	private:
		Node<T> *elements;
		unsigned int size;
	public:
		ListSet();
		~ListSet();

		virtual void insert(const T&);
		virtual void remove(const T&);
		virtual bool contains(const T&);

		Node<T> *get_list()const{return elements;}
};
/*----END LIST SET CLASS----*/

//Constructor
template <class T>
ListSet<T>::ListSet():size(0)
{
	elements=NULL;
}

template <class T>
ListSet<T>::~ListSet()
{
	delete []elements;
	size=0;
	elements=NULL;
}

//Insert value
template <class T>
void ListSet<T>::insert(const T& v)
{
	if(!contains(v))
	{
		++size;//Increment size
		if(elements==NULL)//If it was initially empty
		{
			elements=new Node<T>;
			elements->val=v;
			elements->next=NULL;
			return;
		}
		Node<T> *cursor=elements;
		while(cursor->next!=NULL)//Go to last element
			cursor=cursor->next;
		cursor->next=new Node<T>;
		cursor->next->val=v;
		cursor->next->next=NULL;
		cursor=NULL;
	}	
}

//Remove value
template <class T>
void ListSet<T>::remove(const T& v)
{	
	if(size==0) return;
	else if(size==1)//If there is only one element
	{
		size=0;
		delete elements;//Delete element
		elements=NULL;
		return;
	}	
	Node<T> *prev=elements;
	Node<T> *cursor=elements;
	for(unsigned int i=0; i<size; ++i)//Go through the whole list
	{
		if(cursor==NULL) return;//If we are at end
		else if(cursor->val==v)//If this is the value
		{
			prev->next=cursor->next;//Make the previous's next point to the next value. Thus skipping the current value
			delete cursor;//Delete current value
			--size;//Decrement size
			return;
		}
		prev=cursor;//Prev element will be the current value
		cursor=cursor->next;//Current value will be next value
	}
}

//Checks if the value is in elements
template <class T>
bool ListSet<T>::contains(const T& v)
{
	Node<T> *cursor=elements;
	while(cursor!=NULL)
	{
		if(cursor->val==v) return true;
		cursor=cursor->next;
	}	
	return false;
}

/* List Set Iterator */
template <class T>
class LSIterator : public Iterator<T>
{
	private:
		std::queue<T> data;
	public:
		LSIterator(const ListSet<T>&);
		virtual T next();
		virtual T value();
		virtual bool has_next();
};

template <class T> LSIterator<T>::LSIterator(const ListSet<T> &ls)
{
	Node<T> *cursor=ls.get_list();
	while(cursor!=NULL)
	{
		data.push(cursor->val);
		cursor=cursor->next;
	}
}

template <class T> T LSIterator<T>::next()
{
	T val=data.front();
	data.pop();
	return val;
}

template <class T> T LSIterator<T>::value()
{
	return data.front();
}

template <class T> bool LSIterator<T>::has_next()
{
	return !data.empty();
}


#endif
