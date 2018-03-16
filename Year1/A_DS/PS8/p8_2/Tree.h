#ifndef TREE_H
#define TREE_H

#include <queue>
#include <cstddef>
#include <iostream>

template <class T>
struct Tree
{
		T value;
		Tree<T> *left;
		Tree<T> *right;	
};

template <class T>
class BST 
{
	protected:
		Tree<T> *elements;

		unsigned int size;
		unsigned int itr_ind;//Iterator index
		
		void destroy(Tree<T>*);//Destructor
		void premove(Tree<T>*,Tree<T>*,bool,const T&);//Private remove for using throw

		T minimum(Tree<T> *) const;
	public:
		BST();
		~BST();
		
		void insert(const T&);
		void remove(const T&);
		bool contains(const T&) const;

		Tree<T> *get_tree()const{return elements;}
};

//Constructor
template <class T>
BST<T>::BST():size(0),itr_ind(0)
{
	elements=NULL;
}

//Destructor
template <class T> BST<T>::~BST()
{
	destroy(elements);
}

//Destroy tree
template <class T> void BST<T>::destroy(Tree<T> *head)
{
	if(head==NULL) return;

	destroy(head->left);
	destroy(head->right);

	delete head;
	head=NULL;
}

//Check if v is in t
template <class T>
bool BST<T>::contains(const T &v) const
{
	Tree<T> *cursor=elements;
	while(cursor!=NULL)
	{
		if(cursor->value==v) return true;
		else if(v<=cursor->value) cursor=cursor->left;
		else cursor=cursor->right;
	}
	return false;
}

//Insert element in tree
template <class T> void BST<T>::insert(const T& v)
{
	++size;
	if(elements==NULL)
	{
		elements=new Tree<T>;
		elements->left=NULL;
		elements->right=NULL;
		elements->value=v;
		return;
	}

	Tree<T> *cursor=elements;
	while(true)
	{
		if(v<=cursor->value)
		{
			//Towards the left
			if(cursor->left==NULL)
			{
				//Add here
				cursor->left=new Tree<T>;
				cursor->left->value=v;
				cursor->left->left=NULL;
				cursor->left->right=NULL;	
				return;
			}
			else cursor=cursor->left;
		}
		else if(v>cursor->value)
		{
			if(cursor->right==NULL)
			{
				//Add here
				cursor->right=new Tree<T>;
				cursor->right->value=v;
				cursor->right->left=NULL;
				cursor->right->right=NULL;	
				return;
			}
			else cursor=cursor->right;
		}
	}
}

//Remove element in tree
template <class T> void BST<T>::remove(const T&v)
{
	if(contains(v))//For size. Doesn't change complexity though
	{
		--size;
		premove(elements,elements,0,v);
	}
}



//-------------------------PRIVATE FUNCTIONS---------------------------
//
//Private remove element in tree
template <class T> void BST<T>::premove(Tree<T> *head, Tree<T> *parent, bool rchild, const T &v)
{
	if(head==NULL)
		return;
	else if(v==head->value)
	{
		if(head->left==NULL)
		{
			if(head->right==NULL)	//Both NULL
			{	
				if(parent==head)//If it is the root
				{
					delete head;
					elements=NULL;//Just access elements
					return;
				}

				delete head;
				if(rchild) parent->right=NULL;//If head is the right child make the parent's right node point to NULL. If this node equals NULL by itself parent won't know.
				else parent->left=NULL;

				return;
			}

			//L-NULL, R-NOT NULL
			Tree<T> *temp=head->right;
			delete head;
			head=temp;
			return;
		}
		else if(head->right==NULL)//L-NOT NULL, R-NULL
		{
			Tree<T> *temp=head->left;
			delete head;
			head=temp;
			return;
		}
		
		//Find minimum from right
		T val=minimum(head->right);	
		head->value=val;//Set it to current value
		premove(head->right,head,1,val);//Remove that val from right
	}
	else if(v<head->value)
		premove(head->left,head,0,v);
	else premove(head->right,head,1,v);
}

//Smallest element in tree or sub-tree
template <class T> T BST<T>::minimum(Tree <T> *head) const
{
	Tree<T> *cursor=head;
	while(cursor->left!=NULL)
		cursor=cursor->left;
	return cursor->value;	
}
//------------------------END PRIVATE FUNCTIONS----------

template <class T>
class BSTIterator
{
	private:
		std::queue<T> data;//Contains all the elements
		void add_less_order(const Tree<T>*);
	public:
		BSTIterator(const BST<T>&);
		T next();
		bool has_next();
};

template <class T> BSTIterator<T>::BSTIterator(const BST<T> &values)
{
	add_less_order(values.get_tree());	
}

template <class T> void BSTIterator<T>::add_less_order(const Tree<T> *head)
{
	if(head==NULL) return;

	add_less_order(head->left);
	data.push(head->value);
	add_less_order(head->right);
}

template <class T> T BSTIterator<T>::next()
{
	T val=data.front();
	data.pop();
	return val;
}

template <class T> bool BSTIterator<T>::has_next()
{
	return !data.empty();
}

#endif
