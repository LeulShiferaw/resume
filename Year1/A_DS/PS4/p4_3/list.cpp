/*
 * Leul Shiferaw
 * Problem 4
 * Algorithms and Data Structures
 */
#include <iostream>

using namespace std;

template <class T>
class linked_list
{
	public:
		T value;
		linked_list<T> *next;

		linked_list();
		~linked_list(){};
};

//--------linked_list members function begin---------

template <class T>
linked_list<T>::linked_list()
{
	value = 0;
	next=NULL;
}

//--------linked_list member functions end----------

//--------Functions begin----------

template <typename T>
linked_list<T>* concat(linked_list<T>* l1, linked_list<T>* l2)//Return the head of the new list. New list should concatenate l1 and l2.
{
	linked_list<T> *result=NULL, *head=NULL;

	linked_list<T> *newele=NULL;
	linked_list<T> *cursor=l1;
	while(cursor!=NULL)
	{
		//Create new element
		newele = new linked_list<T>();
		newele->value=cursor->value;
		newele->next=NULL;	

		if(result==NULL)//If new list is empty
		{	
			result=newele;
			head = result;
		}
		else 
		{
			result->next=newele;
			result=result->next;
		}

		cursor=cursor->next;
	}

	cursor=l2;//Repeat the same for the second part of the list
	while(cursor!=NULL)
	{
		newele = new linked_list<T>();
		newele->value=cursor->value;
		newele->next=NULL;	

		if(result==NULL)
		{	
			result=newele;
			head = result;
		}
		else
		{
			result->next=newele;
			result=result->next;
		}

		cursor=cursor->next;
	}

	return head;
}

template <typename T>
linked_list<T>* reverse(linked_list<T>* ls)
{
	linked_list<T>* rev=NULL;	

	linked_list<T>* cursor=ls;
	linked_list<T>* newele=NULL;
	while(cursor!=NULL)
	{
		//Create new element
		newele = new linked_list<T>();
		newele->value=cursor->value;
		newele->next=rev; //Place it in the first position
		
		rev=newele;//Make head the first element

		cursor=cursor->next;
	}

	return rev;
}

template <typename T>
void display(linked_list<T>* ls)
{
	while(ls!=NULL)
	{
		cout << ls->value << endl;
		ls=ls->next;
	}
}

template <typename T>
linked_list<T>* add(linked_list<T>* ls, const T &val)
{
	//Create new element
	linked_list<T>* newele = new linked_list<T>();
	newele->value=val;
	newele->next=NULL;

	linked_list<T>* cursor=ls;
	if(cursor==NULL) //If the list is currently empty
		return newele;

	while(cursor->next!=NULL)//Go to last element
		cursor=cursor->next;

	cursor->next=newele;//Add new element

	return ls;//Return head
}
template <typename T>
void destroy(linked_list<T>* ls)
{
	if(ls==NULL)
		return;
	destroy(ls->next);
	delete ls;
	ls=NULL;
}

//----------Functions end-----------

//----------Order Classes begin-----------

template <class A>
class Ord
{
	public:
		Ord(){};
		virtual ~Ord(){};
		virtual bool lessOrEqual(const A &x, const A &y)=0;//Easiest order. It is even a total order
};

class IntSmaller : public Ord<int>
{
	public:
		bool lessOrEqual(const int &x, const int &y) { return x <= y; }
};

class Divisible : public Ord<int>
{
	public:
		bool lessOrEqual(const int &x, const int &y) { if(x==0) return false; return y%x==0; }
};

class Lexicographic : public Ord<string>
{
	public: bool lessOrEqual(const string &x, const string &y) { return x <= y; }
};

//---------Order Classes end-----------

template <class T>
bool sorted(linked_list<T> *head, const Ord<T> &ord)
{
	if(head==NULL)
		return true;
	while(head->next!=NULL)
	{
		if(!ord.lessOrEqual(head->value, head->next->value))
			return false;
		head=head->next;
	}
	return true;
}


//--------Instances begin------------

IntSmaller *is = new IntSmaller();
Divisible *dv = new Divisible();
Lexicographic *lg = new Lexicographic();

//--------Instances end------------

int main()
{

	delete is;
	delete dv;
	delete lg;

	is=NULL;
	dv=NULL;
	lg=NULL;

	return 0;
}
