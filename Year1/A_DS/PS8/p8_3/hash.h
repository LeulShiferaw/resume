#ifndef HASH_H
#define HASH_H

#include "list.h"
#include <queue>
#include <vector>

/* Abstract class for hash sets */
template <class T>
class HashSet
{
	public:
		HashSet(){};
		virtual T hash(const T&)=0;
		bool contains(const T&);
		void insert(const T&);
		void remove(const T&);

		std::vector<ListSet<T> > bucket;
};

//Checks if v is in bucket
template <class T> bool HashSet<T>::contains(const T &v)
{
	return bucket[hash(v)].contains(v);
}

template <class T> void HashSet<T>::insert(const T &v)
{
	bucket[hash(v)].insert(v);//Insert v in its hash's bucket
}

template <class T> void HashSet<T>::remove(const T &v)
{
	bucket[hash(v)].remove(v);//Remove v from its hash's bucket
}

/* Hash Set for last digits */
template <class T>
class LastDigitHashSet : public HashSet<T>
{
	public:
		LastDigitHashSet();	
		virtual T hash(const T&);//Define the hash
		std::vector<ListSet<T> > get_hashset()const{return this->bucket;}
};

//Constructor
//Create the buckets of the possible hashs
template <class T>
LastDigitHashSet<T>::LastDigitHashSet()
{
	ListSet<T> empty_lset;
	for(int i=0; i<10; ++i) this->bucket.push_back(empty_lset);
}

//The hash function
template <class T>
T LastDigitHashSet<T>::hash(const T &v)
{
	return v%10;
}

/* Last Digit Hash Set Iterator */
template <class T>
class LDHSIterator
{
	private:
		std::queue<T> data;
	public:
		LDHSIterator(const LastDigitHashSet<T>&);
		T next();
		T value();
		bool has_next();
};

//Constructor
template <class T> LDHSIterator<T>::LDHSIterator(const LastDigitHashSet<T> &values)
{
	for(unsigned int i=0; i<values.bucket.size(); ++i)
	{
		LSIterator<T> it(values.bucket[i]);
		while(it.has_next())
			data.push(it.next());
	}
}

//Get next value
template <class T> T LDHSIterator<T>::next()
{
	T val=data.front();
	data.pop();
	return val;
}

//Get current value
template <class T> T LDHSIterator<T>::value()
{
	return data.front();
}

//If it has next value
template <class T> bool LDHSIterator<T>::has_next()
{
	return !data.empty();
}

#endif
