/*
 * Problem 5.2
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
struct list
{
	T val;
	list<T> *prev;
	list<T> *next;
};

template <class T>
void swap2(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
list<T>* append(list<T>* ls, T n)
{
	//Create new element
	list<T>* new_ele = new list<T>;
	new_ele->val = n;
	new_ele->next = NULL;

	//If list is empty
	if(ls==NULL)
	{
		new_ele->prev = NULL;
		return new_ele;
	}

	//Go to last element
	list<T> *cursor = ls;
	while(cursor->next!=NULL)
		cursor=cursor->next;

	//Append at last position
	new_ele->prev = cursor;
	cursor->next = new_ele;

	return ls;
}

template <class T>
void destroy(list<T>* ls)
{
	if(ls==NULL)
		return;
	destroy(ls->next);//Destroy the rest first
	delete ls;
}

template <class T>
void display(list<T> *ls)
{
	while(ls!=NULL)
	{
		cout << ls->val << " ";
		ls=ls->next;
	}
	cout << endl;
}

template <class T>
void insertion_sort(list<T>* ls)
{
	if(ls==NULL)
		return;

	list<T>* back_cursor = NULL;
	while(ls!=NULL)
	{
		back_cursor = ls;	
		//Put the last element in the right position
		while(back_cursor!=NULL && back_cursor->prev!=NULL)
		{
			if(back_cursor->prev->val < back_cursor->val)
				break;
			//Switch
			swap2<T>(back_cursor->prev->val, back_cursor->val);
			back_cursor = back_cursor->prev;
		}
		ls=ls->next;//Go to the next element
	}
}

template <class T>
void bubble_sort(list<T> *ls)
{
	if(ls==NULL)
		return;

	//Get the last element
	list<T> *tail=ls;
	while(tail->next!=NULL)
		tail=tail->next;

	bool sorted=false;
	list<T> *cursor=NULL;
	while(!sorted)//Stop if the current iteration proofed there  are no more unordered pairs.
	{
		sorted=true;
		cursor=tail;
		while(cursor->prev!=NULL)
		{
			if(cursor->prev->val > cursor->val)
			{
				sorted=false;
				swap2<T>(cursor->prev->val, cursor->val);//Keep swapping unordered pairs
			}
			cursor=cursor->prev;
		}	
	}
}

int rand_range(const int &l, const int &h)
{
	return rand()%(h-l+1)+l;
}

int main()
{
	srand(time(0));

	list<int> *ls=NULL;
	for(int i=0; i<10; ++i)
		ls=append<int>(ls, rand_range(1, 100));

	cout << "Unsorted: ";
	display(ls);

	insertion_sort<int>(ls);	

	cout << "Sorted: ";
	display(ls);

	destroy(ls);	
	return 0;
}

