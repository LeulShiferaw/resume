//This program should print 10 to 0 in decreasing order
#include "stack.hpp"
#include <iostream>

int main()
{
	Stack<int> stack;

	try
	{
		for(int i=0; i<10; ++i)
			stack.push(i);

		while(!stack.is_empty())
			cout << stack.pop() << " ";
		cout << endl;
	}
	catch(...)
	{
		cout << "Error!" << endl;
	}
	return 0;
}
