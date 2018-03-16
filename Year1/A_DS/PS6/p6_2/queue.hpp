#include <list>

using namespace std;

template <class T>
class Queue
{
	private:
		list<T> elements;
	public:
		Queue();
		~Queue();
		T dequeue();
		bool is_empty();
		void enqueue(const T&);
};

template <class T>
Queue<T>::Queue(){}

template <class T>
Queue<T>::~Queue()
{
	elements.clear();
}

template <class T>
T Queue<T>::dequeue()
{
	if(is_empty())
		throw "Error dequeuing!\n";

	T temp=elements.back();
	elements.pop_back();
	return temp;
}

template <class T>
bool Queue<T>::is_empty()
{
	return elements.size()==0;	
}

template <class T>
void Queue<T>::enqueue(const T& n)
{
	elements.push_front(n);
}
