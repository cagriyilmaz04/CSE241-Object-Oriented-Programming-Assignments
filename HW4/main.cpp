#include "DayOfYearSet.h"
using namespace cagri;

ostream& operator <<(ostream& outputStream,  DayofYearSet datas) {
		 DayofYearSet::DayofYear* list = datas.getDatas();
		int size = datas.getSize();
		if (size > 0) {
			int i;
			outputStream << "Month Year\n";
			for (i = 0;i < size;++i) {
				outputStream << list[i].getMonth() << " " << list[i].getDay() << endl;
			}
		}
		return outputStream;
	}

void testFunction1( DayofYearSet& datasMember1,  DayofYearSet& datasMember2);
void testFunction( DayofYearSet datasMember1,  DayofYearSet datasMember2);

int main() {
	 DayofYearSet  mutablelist, arrayList;
	testFunction1(mutablelist, arrayList);

	return 0;

}

void testFunction1( DayofYearSet& datasMember1,  DayofYearSet& datasMember2) {
	//int day, month;
	 DayofYearSet::DayofYear datas;
	datas.setDay(10);
	datas.setMonth(10);
	datasMember1.add(datas);
	datas.setDay(2);
	datas.setMonth(2);
	datasMember1.add(datas);
	datas.setDay(3);
	datas.setMonth(3);
	datasMember1.add(datas);
	datas.setDay(4);
	datas.setMonth(4);
	datasMember1.add(datas);
	datas.setDay(5);
	datas.setMonth(5);
	datasMember1.add(datas);
	datas.setDay(10);
	datas.setMonth(5);

	datasMember2.add(datas);
	datas.setDay(6);
	datas.setMonth(6);
	datasMember2.add(datas);
	datas.setDay(7);
	datas.setMonth(7);
	datasMember2.add(datas);
	datas.setDay(8);
	datas.setMonth(8);
	datasMember2.add(datas);
	datas.setDay(9);
	datas.setMonth(9);
	datasMember2.add(datas);
	 std::cout << "First object\n";
	 std::cout << datasMember1 << endl;
	 std::cout << "Second object\n";
	 std::cout << datasMember2 << endl;
	 DayofYearSet dorduncu;
	dorduncu = !(datasMember1) ^ !datasMember2;
	 DayofYearSet x;
	x = datasMember1 + datasMember2;
	 std::cout << "After addition " << x.getSize() << endl;
	 std::cout << x;
	ofstream file("output.txt");
	file << x;
	x = datasMember1 - datasMember2;
	 std::cout << "After substraction " << x.getSize() << endl;
	 std::cout << x;
	x = datasMember1 ^ datasMember2;
	if (x.getSize() == 0) {
		 std::cout << "There is no element intersection set\n";
	}
	else {
		 std::cout << "After intersection\n";
		 std::cout << x;
	}

	x = datasMember1 + datasMember2;
	x = !x;
	 std::cout << "After complementation " << x.getSize() << endl;
	 std::cout << x << endl;
	if (dorduncu == x) {
		 std::cout << "The same for De morgan's rules\n";
	
	}
}

void testFunction( DayofYearSet datasMember1,  DayofYearSet datasMember2) {

	//int day, month;
	 DayofYearSet::DayofYear datas;
	datas.setDay(10);
	datas.setMonth(10);
	datasMember1.add(datas);
	datas.setDay(2);
	datas.setMonth(2);
	datasMember1.add(datas);
	datas.setDay(3);
	datas.setMonth(3);
	datasMember1.add(datas);
	datas.setDay(4);
	datas.setMonth(4);
	datasMember1.add(datas);
	datas.setDay(5);
	datas.setMonth(5);
	datasMember1.add(datas);
	datas.setDay(10);
	datas.setMonth(5);

	datasMember2.add(datas);
	datas.setDay(6);
	datas.setMonth(6);
	datasMember2.add(datas);
	datas.setDay(7);
	datas.setMonth(7);
	datasMember2.add(datas);
	datas.setDay(8);
	datas.setMonth(8);
	datasMember2.add(datas);
	datas.setDay(9);
	datas.setMonth(9);
	datasMember2.add(datas);
	 std::cout << "First object\n";
	 std::cout << datasMember1 << endl;
	 std::cout << "Second object\n";
	 std::cout << datasMember2 << endl;
	 DayofYearSet dorduncu;
	dorduncu = !(datasMember1) ^ !datasMember2;
	 DayofYearSet x;
	x = datasMember1 + datasMember2;
	 std::cout << "After addition " << x.getSize() << endl;
	 std::cout << x;
	ofstream file("output1.txt");
	file << x;
	x = datasMember1 - datasMember2;
	 std::cout << "After substraction " << x.getSize() << endl;
	 std::cout << x;
	x = datasMember1 ^ datasMember2;
	if (x.getSize() == 0) {
		 std::cout << "There is no element intersection set\n";
	}
	else {
		 std::cout << "After intersection\n";
		 std::cout << x;
	}

	x = datasMember1 + datasMember2;
	x = !x;
	 std::cout << "After complementation " << x.getSize() << endl;
	 std::cout << x << endl;
	if (dorduncu == x) {
		 std::cout << "The same for De morgan's rules\n";
	}


}