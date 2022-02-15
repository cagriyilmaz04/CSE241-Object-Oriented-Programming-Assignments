#include <iostream>
#include <vector>
#include <fstream>

#ifndef DayofYearSet_h_
#define DayofYearSet_h_

namespace cagri{
	using std::ostream;
	using std::ofstream;
	using std::vector;
	using std::endl;
	class DayofYearSet {
		public:
			class DayofYear {
			public:
				inline int getDay() { return day; }
				inline int getMonth() { return month; }
				void setDay(int Day) { day = Day; }
				void setMonth(int Month) { month = Month; }
				DayofYear(int Month, int Day);
				DayofYear();
			private:
				int year;
				int month;
				int day;
			};
			DayofYearSet();
			DayofYearSet(vector<DayofYear> data);
			DayofYear& operator[] (int index);
			friend bool operator ==( DayofYearSet datasMember1, DayofYearSet datasMember2);
			friend bool operator !=(DayofYearSet datasMember1, DayofYearSet datasMember2);
			friend ostream& operator <<(ostream& outputStream, DayofYear* datasMember1);
			friend DayofYearSet operator-(DayofYearSet datasMember1, DayofYearSet datasMember2);
			friend DayofYearSet operator ^(DayofYearSet datasMember1, DayofYearSet datasMember2);
			friend DayofYearSet operator +(DayofYearSet datasMember1, DayofYearSet datasMember2);
			friend DayofYearSet operator !(DayofYearSet datasMember1);
			void add(DayofYear element);
			static int NumberofActiveGames();
			bool areTheSameSets(DayofYearSet datasMember1);
			bool isEqual(DayofYear first, DayofYear second);
			bool duplicate(DayofYear element);
			inline DayofYear* getDatas() { return datasMember; }
			void setSize(int value) { size = value; }
			inline int getSize() { return size; }
			void setList(DayofYear* datasMember);
			inline void setDatasMember(DayofYear* datasMemberNew) { datasMember = datasMemberNew; };
			void remove(const int indeks);
			
		private:
			static int activeGames;
			DayofYear* datasMember;
			int size = 0;

		};
}
#endif