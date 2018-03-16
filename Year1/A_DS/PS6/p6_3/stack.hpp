#include <list>

using namespace std;

template <class T>
class Stack
{
	private:
		list<T> elements;
	public:
		Stack();
		~Stack();
		T pop();
		bool is_empty();
		void push(const T &);
};

template <class T>
Stack<T>::Stack(){}

template <class T>
Stack<T>::~Stack()
{
	elements.clear();
}

template <class T>
void Stack<T>::push(const T& n)
{
	elements.push_front(n);
}

template <class T>
T Stack<T>::pop()
{
	if(is_empty())
		throw "Error poping!\n";
	T temp=elements.front();
	elements.pop_front();
	return temp;
}

template <class T>
bool Stack<T>::is_empty()
{
	return elements.size()==0;
}
