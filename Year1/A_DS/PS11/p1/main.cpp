//This is c++11
#include <deque>
#include <iostream>

using namespace std;

template <class T, class S>
deque<S> mapAux(deque<T> list, S (*f)(T), deque<S> result)
{
	if(list.size()==0)
		return result;
	result.push_back(f(list.front()));
	list.pop_front();
	return mapAux(list,f,result);
}

template <class T, class S>
deque<S> map(const deque<T> &list, S (*f)(T))
{
	deque<S> result;
	return mapAux(list,f,result);	
}

double fun(int x)
{
	return x*2 + 0.1;
}

int main()
{
	deque<int> list;
	for(int i=0; i<10; ++i)
		list.push_back(i);

	deque<double> result=map(list,fun);	
	for(int i=0; i<10; ++i)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
