#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include <string>
using namespace std;

namespace cagri_HW6
{
    template<class T>
    class GTUIterator {
    public:
        GTUIterator(T* tenim) :ptr(tenim) {}
        GTUIterator();
        GTUIterator operator++() {
            ptr++;
            return *this;
        }
        GTUIterator operator++(int junk)
        {
            ptr++;
            return *this;
        }
        GTUIterator operator--() {
            ptr--;
            return *this;
        }
        GTUIterator operator--(int junk)
        {
            ptr--;
            return *this;
        }
        GTUIterator& operator=(const GTUIterator& rightS) {
            ptr = rightS.ptr;
            return *this;

        }
        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }
        bool operator==(const GTUIterator& other) const { return ptr == other.ptr; }
        bool operator!=(const GTUIterator& other) const { return ptr != other.ptr; }
        T* getData() const { return ptr; }
    protected:
        T* ptr;

    };
    
    template<class T>
    GTUIterator<T>::GTUIterator() {}
    }

#endif