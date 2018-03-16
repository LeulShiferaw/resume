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

int main()
{
	linked_list<int> *l1=NULL, *l2=NULL, *l3=NULL, *l4=NULL, *l5=NULL;//L1, L2 - lists, L3 - L1, L2 concatenated, L4 - L1 reversed, L5 - L2 reversed
	
	for(int i=0; i<3; ++i)
		l1=add(l1, i);

	for(int i=3; i<5; ++i)
		l2=add(l2, i);

	l3=concat(l1, l2);
	l4=reverse(l1);
	l5=reverse(l2);

	cout << "L1:" << endl;
	display(l1);

	cout << "L2:" << endl;
	display(l2);

	cout << "L3 [concat(L1, L2)]:" << endl;
	display(l3);

	cout << "L4 [reverse(L1)]:" << endl;
	display(l4);

	cout << "L5 [reverse(L2)]:" << endl;
	display(l5);

	destroy(l1);
	destroy(l2);
	destroy(l3);
	destroy(l4);
	destroy(l5);

	return 0;
}
