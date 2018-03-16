#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include "iterator.h"


template <class T>
struct Node
{
	T val;
	std::vector<Node<T>> children;

	Node():val(0){};	
	
	//Copy constructor for queue
	Node(const Node<T> &rhs)
	{
		val=rhs.val;
		children=rhs.children;
	}
};

//The iterator functions are built in with the Tree
template <class T>
class Tree : public Iterator<T>
{
	private:
		Node<T> root; 
		
		int index_dfs; //Index tracking for bfs iterator functions
		int index_bfs; //Index tracking for dfs iterator functions
		bool hasnext_dfs; //Does dfs iterator have next elements
		bool hasnext_bfs; //Does bfs iterator have next elements

		//Private functions, b/c throwing is faster
		void pnext_bfs(const Tree&);
		void pnext_dfs(const Tree&,int&,bool);
	public:
		Tree(const Node<T>&);	

		//Virtual Methods
		virtual T next_dfs();
		virtual T next_bfs();
		virtual bool has_next_dfs();
		virtual bool has_next_bfs();
};

#endif
