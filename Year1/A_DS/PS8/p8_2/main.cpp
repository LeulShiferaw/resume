#include "Tree.h"

using namespace std;

int main()
{
	BST<int> tree;
	tree.insert(3);
	tree.insert(1);
	tree.insert(5);
	tree.insert(4);
	tree.insert(7);
	tree.remove(3);

	BSTIterator<int> it(tree);
	while(it.has_next())
		cout << it.next() << " ";
	cout << endl;
	return 0;
}
