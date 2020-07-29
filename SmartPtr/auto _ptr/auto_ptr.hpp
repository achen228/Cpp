#pragma once
#include <iostream>
using namespace std;

namespace Auto_Ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				ap._ptr = nullptr;		
			}
			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;			
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void TestAuto_Ptr()
	{
		auto_ptr<int> ap1(new int);
		auto_ptr<int> ap2(ap1);

		auto_ptr<int> ap3(new int);
		ap3 = ap2;

		//缺陷：ap2 = ap1场景下ap1就悬空了，访问就会报错，如果不熟悉他的特性就会被坑
		//*ap1 = 10;
	}
}
