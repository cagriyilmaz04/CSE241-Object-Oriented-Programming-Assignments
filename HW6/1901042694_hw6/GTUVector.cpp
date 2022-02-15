#include "GTUVector.h"

namespace cagri_HW6
{
	template<class T>
void GTUVector<T>::erase(GTUIterator<T>& iter) {
	GTUIterator<T> temp = this->begin();
	int i = 0;
	while (temp != iter) {
		++i;
		++temp;
	}
	
	if (i >= used) {
		try {
			throw "WARNING: Index cannot be greater than SIZE\n";
		}
		catch (const char* error) {
			cout << error;
		}
	}
	else {
		bool flag = false;
		for (auto iter_temp = this->begin(); iter_temp != this->end(); ++iter_temp) {
			if (*(iter_temp) == *iter) {
				cout << "Cagri\n";
				for (auto iter2 = iter_temp; iter2 != this->end(); ++iter2)
				{
					*(iter2) = *(iter2.getData() + 1);

					flag = true;
				}
			}
		}
		if (flag)
			this->capacity--;
		if (this->capacity <= this->capacity / 2)
			this->capacity /= 2;

	}

}

template<class T>
GTUIteratorConst<T> GTUVector<T>::cbegin() {
	return GTUIteratorConst<T>(vector.get());
}
template<class T>
GTUIteratorConst<T> GTUVector<T>::cend() {
	return GTUIteratorConst<T>(vector.get() + used);
}

template<class T>
GTUVector<T>::GTUVector(int size) {

	if (size == 0) {
		capacity = 2;
	}
	else {
		capacity = size * 2;
	}
	std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });
	vector = sp;
}

template<class T>
T& GTUVector<T>::operator[](int index) {
	return vector.get()[index];

}
template <class T>
const T GTUVector<T>::operator[](int index) const {
	return vector.get()[index];

}
template <class T>
GTUIterator<T> GTUVector<T>::begin() {
	return GTUIterator<T>(vector.get());
}
template <class T>
GTUIterator<T> GTUVector<T>::end() {
	return GTUIterator<T>(vector.get() + used);
}
template<class T>
void GTUVector<T>::clear() {

	used = 0;

	std::shared_ptr<T> sp1(new T[capacity], [](T* p) { delete[] p; });
	sp1 = vector;
	vector.~shared_ptr();
	std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });
	vector = sp1;

}
template <class T>
void GTUVector<T>::add(T& element) {

	//std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });

	capacity = capacity * 2;
	int  i;
	vector.get()[used] = element;
	//vector = sp;
	//cout << vector.get()[used]<< "\n";
	used++;
}
template <class T>
int GTUVector<T>::size() const { return used; }
template<class T>
bool GTUVector<T>::empty() const { return used == 0; }


}