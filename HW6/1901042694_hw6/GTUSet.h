#ifndef GTUSET_H
#define GTUSET_H
#include <iostream>
#include <memory>
#include "Iterable.h"


using namespace cagri_HW6;

namespace cagri_HW6
{
    template<class T>
class GTUSet :public Iterable<T> {
public:
	GTUSet();
	//Virtual Functions
	bool empty() const;
	int size() const;
	void insert(T data);
	void add(T& element);
	GTUSet<T> intersect(GTUSet<T> other);
	GTUSet<T> setUnion(GTUSet<T> other);
	void sortedSet(GTUIterator<T> first, GTUIterator<T> second);
	GTUIterator<T> begin();
	GTUIterator<T> end();
	GTUIteratorConst<T> cbegin();
	GTUIteratorConst<T> cend();
	void erase(GTUIterator<T>& position);
	void clear();
	GTUIterator<T> find(T data) const;
	//Getter and setter
	int getUsed() const { return used; }
	int getCapacity() const { return capacity; }
	shared_ptr<T> getData() const { return vector; }
	void setUsed(int Used) { used = Used; }
	void setCapacity(int Capacity) { capacity = Capacity; }
	void setVector(shared_ptr<T> Vector) { vector = Vector; }
private:
	int used = 0;
	int capacity = 1;
	shared_ptr <T> vector;
	bool itContains(T data);
};
    
}
#endif