#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	ListSet<int> set;
	set.insert(1);
	set.insert(1);
	set.insert(2);
	set.insert(7);
	set.insert(6);

	LSIterator<int> it(set);
	while(it.has_next())
		cout << it.next() << " ";
	cout << endl;
	return 0;
}
