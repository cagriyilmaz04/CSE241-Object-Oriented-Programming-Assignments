#ifndef GTUVECTOR_H
#define GTUVECTOR_H
#include <iostream>
#include <memory>
#include "Iterable.h"

using namespace cagri_HW6;


namespace cagri_HW6
{
    template<class T>
class GTUVector :public Iterable<T> {
public:
	GTUVector(int size);
	bool empty() const;
	int size() const;
	void erase(GTUIterator<T>& position);
	GTUIterator<T> begin();
	GTUIterator<T> end();
	GTUIteratorConst<T> cbegin();
	GTUIteratorConst<T> cend();
	void clear();

	T& operator[] (int index);
	const T operator[](int index) const;
	void add(T& element);

	
private:
	int used = 0;
	int capacity = 1;
	shared_ptr <T> vector;

};
}
#endif