
#include "GTUSet.h"

namespace cagri_HW6
{
	template<class T>
void GTUSet<T>::clear() {

	used = 0;

	std::shared_ptr<T> sp1(new T[capacity], [](T* p) { delete[] p; });
	sp1 = vector;
	vector.~shared_ptr();
	std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });
	vector = sp1;
}
template<class T>
void GTUSet<T>::sortedSet(GTUIterator<T> first, GTUIterator<T> second) {
	GTUIterator<T> i, j;
	T data;
	for (i = first;i != second;++i) {
		for (j = first;j != second;++j) {
			if (*i < *j) {

				data = *i;
				*i = *j;
				*j = data;
			}
		}
	}
}
template<class T>
GTUSet<T> GTUSet<T>::intersect(GTUSet<T> other) {
	GTUSet<T> returnedValue;
	GTUIteratorConst<T> first = this->cbegin();
	GTUIteratorConst<T> second = other.cbegin();
	for (first = this->cbegin();first != this->cend();++first) {
		for (second = other.cbegin();second != other.cend();++second) {

			if (*(first) == *(second)) {

				T data = *first;
				returnedValue.add(data);
				//	returnedValue.add(second->getPtr_());

			}
		}

	}

	return returnedValue;
}

template<class T>
bool GTUSet<T>::itContains(T data) {
	GTUIteratorConst<T> cagri = cbegin();
	bool flag = false;
	for (;cagri != cend();++cagri) {
		if (data == *cagri) {
			flag = true;
			break;
		}
	}
	return flag;
}

template<class T>
GTUSet<T>::GTUSet() {
	capacity = 50;
	std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });
	vector = sp;
}
template<class T>
void GTUSet<T>::add(T& element) {
	//std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });
	if (used >= capacity) {
		capacity = capacity * 2;
	}
	else {}
	int  i;
	if (used >= 1) {
		if (itContains(element) == false) {
			vector.get()[used] = element;
			used++;
		}
	}
	else {
		vector.get()[used] = element;
		used++;
	}
	sortedSet(begin(), end());


}

template<class T>
bool GTUSet<T>::empty() const { return used == 0; }
template <class T>
int GTUSet<T>::size() const { return used; }
template<class T>
GTUIteratorConst<T> GTUSet<T>::cbegin() {
	return GTUIteratorConst<T>(vector.get());
}
template<class T>
GTUIteratorConst<T> GTUSet<T>::cend() {
	return GTUIteratorConst<T>(vector.get() + used);
}
template <class T>
GTUIterator<T> GTUSet<T>::begin() {
	return GTUIterator<T>(vector.get());
}
template <class T>
GTUIterator<T> GTUSet<T>::end() {
	return GTUIterator<T>(vector.get() + used);
}

template<class T>
GTUSet<T> GTUSet<T>::setUnion(GTUSet<T> other) {
	GTUSet<T> returnedValue;
	GTUIteratorConst<T> first = this->cbegin();
	GTUIteratorConst<T> second = other.cbegin();
	bool flag = false;
	for (first = this->cbegin();first != this->cend();++first) {
		T data = *first;
		returnedValue.add(data);
	}
	for (second = other.cbegin();second != other.cend();second++) {
		T data = *second;
		if (itContains(data) == false) {
			returnedValue.add(data);
		}

	}
	return returnedValue;

}
template<class T>
GTUIterator<T> GTUSet<T>::find(T data)const {
	GTUIterator<T> temp = this->begin();
	for (;temp != this->end();++temp) {
		if (*temp == data) {
			return temp;
		}

	}

	return temp;
}
template <class T>
void GTUSet<T>::erase(GTUIterator<T>& iter) {
	GTUIterator<T> temp = this->begin();
	int i = 0;
	while (temp != iter) {
		++i;
		++temp;
	}
	cout << i << " " << used << endl;
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
				for (auto temp_iter2 = iter_temp; temp_iter2 != this->end(); ++temp_iter2){
					*(temp_iter2) = *(temp_iter2.getData() + 1);

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



}