#include <cstddef>

template <class T>
class Buffer
{
	private:
		int n, begin, size;
		T* elements;
	public:
		Buffer(const unsigned int &);
		~Buffer();	
		void enqueue(const T &);
		T dequeue();
};

/* --------Class Buffer Implementations--------- */
//Constructor
template <class T>
Buffer<T>::Buffer(const unsigned int &x)
{
	n=x;
	begin=0;
	size=0;
	elements=new T[n];

	if(elements==NULL)
		throw "Unable to allocate properly";
}

//Destructor
template <class T>
Buffer<T>::~Buffer()
{
	if(elements)
	{
		delete []elements;
		elements=NULL;
	}
}

//Add element
template <class T>
void Buffer<T>::enqueue(const T &x)
{
	if(size>=n)
		throw "Buffer Overflow";

	elements[(begin+size)%n]=x;
	++size;
}

//Remove element
template <class T>
T Buffer<T>::dequeue()
{
	if(size<=0)
		throw "Buffer Underflow";

	T temp=elements[begin];

	begin=(begin+1)%n;
	--size; 				//Doesn't have to be modulo n. Because that can never happen.

	return temp;
}
/* ---------Class Buffer Implementations*-------- */


