#include "Tree.h"
#include <deque>

//Parametric Constructor
template <class T>
Tree<T>::Tree(const Node<T>& v):index_dfs(0),index_bfs(0),hasnext_dfs(true),hasnext_bfs(true)
{
	root.val=v.val;
	root.children=v.children;
}

//Private next for dfs, it throws which bypasses the call stack
template <class T>
void Tree<T>::pnext_dfs(const Tree<T>& head, int &curr_ind, bool last)//last - potentioal last element
{
	//If we are the right element
	if(curr_ind==index_dfs)
	{
		++index_dfs;//Next elements index
		if(last)//if this is potentialy the last element, which are always the last elements from the children
			if(head.root.children.size()==0)
				hasnext_dfs=false;
		throw head.root.val;
	}
	
	int n=head.root.children.size();
	for(int i=0; i<n; ++i)
	{
		++curr_ind;
		pnext_dfs(head.root.children[i],curr_ind,(i==n-1)&&last);//If its parent is potentialy the last element and it is the last element from the children then it could all be the last element
	}
}

//Public next for dfs
//Actual function call from main
template <class T>
T Tree<T>::next_dfs()
{
	try
	{
		int curr_ind=0;
		pnext_dfs(root,curr_ind,true);
	}
	catch(const T &val)
	{
		return val;
	}

	//If it doesn't throw anything
	throw "No next element!\n";
}

//Checks if it has next element
template <class T>
bool Tree<T>::has_next_dfs()
{
	return hasnext_dfs;
}

//Private next for bfs
template <class T>
void Tree<T>::pnext_bfs(const Tree<T> &head)
{
	int i=0;
	Node<T> curr;
	unsigned int n;
	std::deque<Node<T>> needToVisit;

	needToVisit.push_back(head.root);//First visit the root value
	while(1)
	{
		curr=needToVisit.front();
		needToVisit.pop_front();
		
		if(i==index_bfs)//If it is the right element
		{
			++index_bfs;
			if(needToVisit.size()==0 && curr.children.size()==0)//If there are no more elements to visit and it doesn't have any children then it is the last element
				hasnext_bfs=false;
			throw curr;
		}
		n=curr.children.size();
		for(unsigned int j=0; j<n; ++j)
			needToVisit.push_back(curr.children[j]);
		++i;
	}
}

//Public next for bfs
template <class T>
T Tree<T>::next_bfs()
{
	try
	{
		pnext_bfs(root);
	}
	catch(Node<T> &val)
	{
		return val.val;			
	}

	//If it doesn't throw anything
	//But this will never run; since there is a check in the main function
	throw "No Next Element!\n";
}	

//Checks if bfs has next element
template <class T>
bool Tree<T>::has_next_bfs()
{
	return hasnext_bfs;
}

template class Tree<int>;
template class Node<int>;
