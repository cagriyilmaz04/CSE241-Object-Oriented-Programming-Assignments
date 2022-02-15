#ifndef GTUARRAY_H
#define GTUARRAY_H
#include <iostream>
#include <memory>
#include "Iterable.h"

using namespace cagri_HW6;


namespace cagri_HW6
{
   template<class T, int SIZE>
class GTUArray :public Iterable<T> {
public:
	GTUArray();

	shared_ptr<T> getData() { return data; }
	bool empty() const;
	int size() const;
	void erase(GTUIterator<T>& position);
	GTUIterator<T> begin();
	GTUIterator<T> end();
	GTUIteratorConst<T> cbegin();
	GTUIteratorConst<T> cend();
	T& operator[] (int index);
	const T& operator[](int index) const;
	void clear();
private:
	void add(T& element);
	int used = 0;
	int capacity = SIZE;
	shared_ptr<T> data;
};
}
#endif