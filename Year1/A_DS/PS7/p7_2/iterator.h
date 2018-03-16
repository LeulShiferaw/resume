#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator
{
	private:
	public:
		virtual T next_dfs()=0;
		virtual T next_bfs()=0;
		virtual bool has_next_dfs()=0;
		virtual bool has_next_bfs()=0;
};
#endif
