#include "GTUArray.h"
#include <exception>

namespace cagri_HW6
{
	template<class T, int SIZE>
void GTUArray<T, SIZE>::add(T& element) {
	data.get()[used] = element;
	++used;
}

template<class T, int SIZE>
GTUArray<T, SIZE>::GTUArray() {
	//Initialize our array
	std::shared_ptr<T> sp(new T[capacity], [](T* p) { delete[] p; });
	data = sp;
}
template<class T, int SIZE>
GTUIteratorConst<T> GTUArray<T, SIZE>::cbegin() {
	return GTUIteratorConst<T>(data.get());
}
template<class T, int SIZE>
GTUIteratorConst<T> GTUArray<T, SIZE>::cend() {
	return GTUIteratorConst<T>(data.get() + used);
}
template<class T, int SIZE>
GTUIterator<T>  GTUArray<T, SIZE>::begin() {
	return GTUIterator<T>(data.get());
}
template<class T, int SIZE>
GTUIterator<T>  GTUArray<T, SIZE>::end() {
	return GTUIterator<T>(data.get() + SIZE);
}
template<class T, int SIZE>
bool GTUArray<T, SIZE>::empty() const {
	return capacity == 0;
};

template<class T, int SIZE>
const T& GTUArray<T, SIZE>::operator[](int index) const {
	try {
		if ((index >= 0 && index < SIZE)) {
			return data.get()[index];
		}
	}
	catch (string s) {
		s = "Your value must be between 0 and ";
		cout << s << SIZE - 1 << endl;

	}

}
template<class T, int SIZE>
int GTUArray<T, SIZE>::size() const { return used; }
template<class T, int SIZE>
void GTUArray<T, SIZE>::erase(GTUIterator<T>& iter) {
	
		GTUIterator<T> temp = this->begin();
		int i = 0;
		while (temp != iter) {
			++i;
			++temp;
		}
		
		const string cagri = "You cannot do this\n";
		if (i >= SIZE) {
			try {
				throw "WARNING: Index cannot be greater than SIZE\n";
			}
			catch (const char* error) {
				cout << error;
			}
		}
		else {
			bool flag = false;
			for (auto iter_temp = this->begin(); iter_temp != this->end(); ++iter_temp)	{
				if (*(iter_temp) == *iter)	{
					for (auto iter2 = iter_temp; iter2 != this->end(); ++iter2){
						*(iter2) = *(iter2.getData() + 1);
							
						flag = true;
					}
				}
			}
			if (flag==true){
			
			capacity=SIZE;
			--capacity;
			}
				
			
			
		}
	
}


template<class T, int SIZE>
void GTUArray <T, SIZE>::clear() {


	std::shared_ptr<T> sp1(new T[used], [](T* p) { delete[] p; });
	sp1 = data;
	data.~shared_ptr();
	std::shared_ptr<T> sp(new T[used], [](T* p) { delete[] p; });
	used = 0;
	data = sp1;

}
template<class T, int SIZE>
T& GTUArray<T, SIZE>::operator[](int index) {

	try {
		return data.get()[index];
	}
	catch (const char* message) {

		cout << message;
	}

}
}