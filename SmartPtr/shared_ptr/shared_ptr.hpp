#pragma once
#include <iostream>
#include <thread>
using namespace std;

namespace Shared_Ptr
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			: _ptr(ptr)
			, _pcount(new int(1))
		{}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				if (--(*_pcount) == 0)
				{
					if (_ptr)
					{
						cout << "delete:" << _ptr << endl;
						delete _ptr;
						_ptr = nullptr;
					}
					delete _pcount;
					_pcount = nullptr;
				}

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
			}
			return *this;
		}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				if (_ptr)
				{
					cout << "delete:" << _ptr << endl;
					delete _ptr;
					_ptr = nullptr;
				}

				delete _pcount;
				_pcount = nullptr;
			}
		}

		int UsePcount()
		{
			return *_pcount;
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
		int* _pcount; //引用计数
	};

	void TestShared_Ptr1()
	{
		shared_ptr<int> sp1(new int);
		shared_ptr<int> sp2(sp1);

		shared_ptr<int> sp3(new int);
		shared_ptr<int> sp4(sp3);
		shared_ptr<int> sp5(sp3);

		sp1 = sp4;
	}

	void TestShared_Ptr2()
	{
		shared_ptr<int> sp(new int);
		cout << sp.UsePcount() << endl;

		//线程安全问题
		//引用计数的++/--不是原子操作，两个线程有可能会同时进行
		//比如：开始时，sp的_pcount是1，然后sp1的_pcount++时，sp2的_pcount同时也++
		//这时_pcount是2，然后sp1的_pcount析构，sp2的_pcount也析构，此时_pcount为0，资源被释放，sp被悬空出错
		//因此需要对其进行加锁解锁操作
		int n = 10000;
		thread t1([&]()
		{
			for (int i = 0; i < n; ++i)
			{
				shared_ptr<int> sp1(sp);
			}		
		});

		thread t2([&]()
		{
			for (int i = 0; i < n; ++i)
			{
				shared_ptr<int> sp2(sp);
			}
		});

		t1.join();
		t2.join();

		cout << sp.UsePcount() << endl;
	}
}
