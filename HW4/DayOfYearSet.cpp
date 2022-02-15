#include "DayOfYearSet.h"

namespace cagri{


	int  DayofYearSet::activeGames = 0;
	int  DayofYearSet::NumberofActiveGames() { return activeGames; }
	 DayofYearSet::DayofYear&  DayofYearSet:: operator[](int index) {
		 DayofYearSet::DayofYear* list = getDatas();
		if (index < 0) {
			 std::cerr << "Wrong index";
			exit(1);
		}
		else {
			return list[index];
		}
	}
	bool   operator !=( DayofYearSet datasMember1,  DayofYearSet datasMember2) {
		bool flag = false;
		if (!datasMember1.areTheSameSets(datasMember2)) {
			flag = true;
		}

		return flag;
	}
	bool   operator ==( DayofYearSet  datasMember1, DayofYearSet  datasMember2) {
		bool flag = false;
		if (datasMember1.getSize() != datasMember2.getSize()) {
			flag = false;
		}
		else {
			if (datasMember1.areTheSameSets(datasMember2)) {
				flag = true;
			}
		}
		return flag;
	}
	 DayofYearSet  operator +( DayofYearSet datasMember1,  DayofYearSet datasMember2) {
		 DayofYearSet list;
		// DayofYearSet::DayofYear* newList = list.getDatas();
		auto size1 = datasMember1.getSize();
		decltype(size1) size2 = datasMember2.getSize();
		int i;
		for (i = 0;i < size2;++i) {
			datasMember1.add(datasMember2.getDatas()[i]);
		}
		datasMember1.setSize(size1 + size2);
		list = datasMember1;
		return list;

	}
	void  DayofYearSet::setList(DayofYear* datasMember1) {
		datasMember = datasMember1;
	}

	 DayofYearSet::DayofYearSet(vector<DayofYear> data) {
		++activeGames;
		datasMember = new DayofYear[365];

	}
	 DayofYearSet::DayofYear::DayofYear(int Month, int Day) : month(Month), day(Day) {

	}
	 DayofYearSet::DayofYear::DayofYear() {

	}
	 DayofYearSet  operator -( DayofYearSet newDataMembers,  DayofYearSet newDataMembers1) {
		int i, j;
		int firstSize = newDataMembers.getSize();
		int secondSize = newDataMembers1.getSize();
		bool flag = false;
		 DayofYearSet returnedList;

		for (i = 0;i < firstSize;++i) {
			for (j = 0;j < secondSize;++j) {
				if (newDataMembers.isEqual(newDataMembers.getDatas()[i], newDataMembers1.getDatas()[j])) {
					flag = true;
					j = secondSize;
				}

			}
			if (flag == false) {
				returnedList.add(newDataMembers.getDatas()[i]);
			}
		}
		return returnedList;
	}
	bool  DayofYearSet::isEqual(DayofYearSet::DayofYear first, DayofYearSet::DayofYear second) {
		return first.getDay() == second.getDay() && first.getMonth() == second.getMonth();
	}
	bool  DayofYearSet::duplicate(DayofYear element) {
		int i;
		bool flag = false;
		DayofYear* data = getDatas();
		int size1 = getSize();

		if (size1 > 0) {
			for (i = 0;i < size1;++i) {

				if (isEqual(data[i], element)) {
					flag = true;
					break;
				}
				else {}
			}
		}
		else if (size1 == 0) {
			flag = false;
		}
		return flag;
	}
	bool  DayofYearSet::areTheSameSets(DayofYearSet second) {
		DayofYear* firstObj = getDatas();
		DayofYear* secondObj = second.getDatas();
		bool flag = false;
		int size1 = getSize();
		if (size1 > 0 && second.getSize() > 0) {
			int i, j;
			for (i = 0;i < size1;++i) {
				for (j = 0;j < second.getSize();++j) {
					if (isEqual(firstObj[i], secondObj[j])) {
						flag = true;
						j = second.getSize();
					}
					else {
						flag = false;
					}

				}
			}
		}
		return flag;
	}


	 DayofYearSet::DayofYearSet() {
		++activeGames;
		datasMember = new DayofYear[1000];

	}
	 DayofYearSet  operator ^( DayofYearSet newDataMembers,  DayofYearSet newDataMembers1) {
		int i, j;
		int firstSize = newDataMembers.getSize();
		int secondSize = newDataMembers1.getSize();

		bool flag = false;
		//int a = 0;
		//const int size = newDataMembers.getSize() + newDataMembers1.getSize();
		 DayofYearSet returnedList;


		for (i = 0;i < firstSize;++i) {

			for (j = 0;j < secondSize;++j) {
				if (newDataMembers.isEqual(newDataMembers.getDatas()[i], newDataMembers1.getDatas()[j])) {
					flag = true;


					j = secondSize;

				}
				else { flag = false; }

			}
			if (flag == true) {
				returnedList.add(newDataMembers.getDatas()[i]);
			}
		}
		return returnedList;
	}

	 DayofYearSet  operator !( DayofYearSet dataMember1) {
		int  j, z, k = 0;
		 DayofYearSet::DayofYear* list = dataMember1.getDatas();
		int size = dataMember1.getSize();

		//to remark day of a year;
		int dayOfaYear[][31] = {
			{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,-1,-1,-1}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,-1}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,-1}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,-1}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,-1}
			,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31} };
		 DayofYearSet newDatas;
		
		 DayofYearSet::DayofYear* newList = new  DayofYearSet::DayofYear[365];

		// This loop finds that complement of our object
		int q = 0;

		bool flag = false;
		for (j = 0;j < 12;++j) {
			for (z = 0;z < 31;++z) {
				if (dayOfaYear[j][z] != -1) {
					for (q = 0;q < size;++q) {
						int day = list[q].getDay();
						--day;
						int month = list[q].getMonth();
						--month;
						if (day == z && month == j) {
							flag = false;
							q = size;
						}
						else {
							flag = true;

						}
					}
					if (flag == true) {

						newList[k].setDay(z);
						newList[k].setMonth(j);
						++k;
						flag = false;
					}
				}
			}
		}
		newDatas.setList(newList);
		newDatas.setSize(k);
		return newDatas;
	}
	void  DayofYearSet::add(DayofYear element) {
		DayofYear* datasMember = getDatas();
		int size1 = getSize();
		if (size1 < 1000) {
			if (!duplicate(element)) {
				*(datasMember + size1) = element;
				setList(datasMember);
				setSize(size1 + 1);
			}

		}
		else {
			 std::cout << "Buraya girdi\n";
		}

	}

	void  DayofYearSet::remove(const int indeks) {
		DayofYear* list = getDatas();
		int i;
		int j = 0;
		const int size = getSize();
		DayofYear* list1 = new DayofYear[size];
		if (indeks < size) {
			if (size > 1) {
				for (i = 0;i < size;++i) {
					if (i < indeks) {
						*(list1 + j) = *(list + i);
						++j;
					}
					else {
						*(list1 + j) = *(list + i + 1);
						j++;
					}
				}
			}
			else {}
			setList(list1);
			setSize(j - 1);
		}

	}
}
