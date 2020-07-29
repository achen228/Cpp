#pragma once
#include <iostream>
using namespace std;

namespace Unique_Ptr
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			: _ptr(ptr)
		{}

		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;

		~unique_ptr()
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

	void TestUnique_Ptr()
	{
		unique_ptr<int> up1(new int);

		//缺陷：如果有需要拷贝的场景，他就没法使用
		//unique_ptr<int> up2(up1);
	}
}
