#include "Tree.h"

using namespace std;

int main()
{
	/*
	 * I can't use brace initialized list because I need a copy constructor for dequeue
	 */
	Node<int> root;
	Node<int> element;//Temporary
	vector<Node<int>> temp_input;//Temporary vector

	//----------CREATE TREE----------------------
	//---I used element multiple times instead of creating a different variable for each----
	element.val=3;//{3,NULL}
	temp_input.push_back(element);//{{3,NULL}}

	element.val=4;//{4,NULL}
	temp_input.push_back(element);//{{3,NULL},{4,NULL}}
		
	element.val=1;//{1,...}
	element.children=temp_input;//{1,{{3,NULL},{4,NULL}}}
	temp_input.clear();
	
	root.val=0;//{0,...}
	root.children.push_back(element);//{0,{{1,{{3,NULL},{4,NULL}}}}}
	element.children.clear();

	element.val=5;//{5,NULL}
	temp_input.push_back(element);//{{{5,NULL}}}

	element.val=6;//{6,NULL}
	temp_input.push_back(element);//{{{5,NULL},{6,NULL}}}

	element.val=7;//{7,NULL}
	temp_input.push_back(element);//{{{5,NULL},{6,NULL},{7,NULL}}}
	
	element.val=2;//{2,...}
	element.children=temp_input;//{2,{{5,NULL},{6,NULL},{7,NULL}}}
	
	root.children.push_back(element);/*{
					      0, 
					      { 
					         {
						   1,
					   	   {{3,NULL},{4,NULL}}
						 },
						 {
						   2,
						   {{5,NULL},{6,NULL},{7,NULL}}
						 }
					      }
					   }
					 */
	//------------FINISH CREATE TREE--------------


	try
	{
		Tree<int> my_tree(root);

		//Print tree
		cout << "TREE" << endl;
		cout << "     0" << endl;
		cout << " 1      2" << endl;
		cout << "3 4   5 6 7" << endl;

		cout << "DFS: ";
		while(my_tree.has_next_dfs())
			cout << my_tree.next_dfs() << " ";
		cout << endl;

		cout << "BFS: ";
		while(my_tree.has_next_bfs())
			cout << my_tree.next_bfs() << " ";
		cout << endl;
	}
	catch(char const* msg)
	{
		cout << msg;
		return 1;
	}
	return 0;
}
