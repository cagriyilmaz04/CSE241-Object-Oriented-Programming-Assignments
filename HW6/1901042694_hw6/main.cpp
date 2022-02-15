#include <iostream>
#include <memory>
#include <string>
#include "GTUSet.cpp"
#include "GTUVector.cpp"
#include "GTUArray.cpp"
#include "GTUIterator.cpp"
#include "GTUIteratorConst.cpp"

using namespace std;
using namespace cagri_HW6;


//I used a function as a parameter because when for_each starts running I want to run only function and user can do whatever user wants.
template<class T>
void for_each(GTUIterator<T> first, GTUIterator<T> second, void f(GTUIterator<T> yeni)) {
    for (GTUIterator<T> temp = first;temp != second;++temp) {
        f(temp);
    }
}
template<class T>
const GTUIterator<T>find(GTUIterator<T> first, GTUIterator<T> second, const T data) {
    GTUIterator<T> returnedValue;
    for (GTUIterator<T> temp = first;temp != second;++temp) {
        if (data == *temp) {
			cout << "Yes There is\n";
            returnedValue = temp;
          
        }

    }
    return returnedValue;
}
template<class T>
void print(GTUIterator<T>data) {
    cout << *data << " ";
}
template<class T>
void sort(GTUIterator<T> first, GTUIterator<T> second) {
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


int main(int argc, char const *argv[])
{
    GTUVector<int> x(5);
	int a=6;
    x.add(a);
	a=53;
    x.add(a);
	a=6;
    x.add(a);
	a=52;
	x.add(a);
	auto a1=x.begin();
	
	
	x.erase(a1);
    cout << x.size()<< " "<< endl;
	GTUSet<string> data;
	string added="Emir";
	data.add(added);
	added="Cagri";
	data.add(added);
	added="Gebze Teknik Universitesi";
	data.add(added);
	added="Agri";
	data.add(added);
	
	for_each(data.begin(),data.end(),print);
	   cout << "\n";
	find(data.begin(),data.end(),added);
   cout << "\n";   
   
   
   GTUArray<double,7> list;
   list[0]=31.0;
   list[1]=24;
   list[2]=41;
   list[3]=77;
   list[4]=4;
   list[5]=34;
   list[6]=12;
 
   cout << "\n";
   sort(list.begin(),list.end());
   for_each(list.begin(),list.end(),print);
   
    return 0;
}

