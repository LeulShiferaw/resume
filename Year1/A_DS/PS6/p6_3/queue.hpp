#include "stack.hpp"

template<class T>
class Queue
{
	private:
		Stack<T> first_list;
		Stack<T> second_list;
	public:
		Queue();
		~Queue();
		void enqueue(const T&);
		T dequeue();
};

template <class T>
Queue<T>::Queue(){};

template <class T>
Queue<T>::~Queue(){};

template <class T>
void Queue<T>::enqueue(const T& val)
{
	while(!second_list.is_empty())
		first_list.push(second_list.pop());
	first_list.push(val);
}

template <class T>
T Queue<T>::dequeue()
{
	while(!first_list.is_empty())
		second_list.push(first_list.pop());
	return second_list.pop();	
}
