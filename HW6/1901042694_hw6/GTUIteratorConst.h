#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H
#include <string>
using namespace std;

namespace cagri_HW6
{
	template<class T>
	class GTUIteratorConst
	{
	public:
		GTUIteratorConst(T* data) : Data(data) {}
		GTUIteratorConst operator++()
		{
			GTUIteratorConst i = *this;
			Data++;
			return i;
		}
		GTUIteratorConst operator++(int junk)
		{
			Data++;
			return *this;
		}
		GTUIteratorConst operator--()
		{
			GTUIteratorConst i = *this;
			Data--;
			return i;
		}
		GTUIteratorConst operator--(int junk)
		{
			Data--;
			return *this;
		}
		GTUIteratorConst& operator=(const GTUIteratorConst& rightS) {
			Data = rightS.Data;
			return *this;

		}
		const T& operator*()const { return *Data; }
		const T* operator->()const { return Data; }
		bool operator==(const GTUIteratorConst& rhs) { return Data == rhs.Data_; }
		bool operator!=(const GTUIteratorConst& rhs) { return Data != rhs.Data; }
		const T* getPtr_() const noexcept
		{
			return Data;
		}

	private:
		T* Data;
	};
}

#endif