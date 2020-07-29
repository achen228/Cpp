#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

namespace Shared_Ptr_ThreadSafe
{
	//声明weak_ptr
	template<class T>
	class weak_ptr;

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			AddRefCount();
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//减减引用计数，如果我是最后一个管理资源的对象，则释放资源
				Release();

				//我开始跟你一起管理资源
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddRefCount();
			}
			return *this;
		}

		~shared_ptr()
		{
			Release();
		}

		void AddRefCount()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Release()
		{
			bool flag = false;

			_pmtx->lock();
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

				flag = true;
			}
			_pmtx->unlock();

			if (flag == true)
			{
				delete _pmtx;
				_pmtx = nullptr;
			}
		}

		int UsePcount()
		{
			return *_pcount;
		}

		T* GetPtr() const
		{
			return _ptr;
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
		mutex* _pmtx;
	};

	void TestShared_Ptr_ThreadSafe1()
	{
		shared_ptr<int> sp(new int);
		cout << sp.UsePcount() << endl;

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

	//严格来说weak_ptr不是智能指针，因为他没有RAII资源管理机制
	//专门解决shared_ptr的循环引用问题
	template<class T>
	class weak_ptr
	{
	public:
		//显示生成默认的构造函数
		weak_ptr() = default;

		weak_ptr(const shared_ptr<T>& sp)
			: _ptr(sp.GetPtr())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.GetPtr();
			return *this;
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

	//shared_ptr的循环引用问题
	struct ListNode
	{
		weak_ptr<ListNode> _next;
		weak_ptr<ListNode> _prev;
		int _val;
		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};

	void TestShared_Ptr_ThreadSafe2()
	{
		shared_ptr<ListNode> sp1(new ListNode);
		shared_ptr<ListNode> sp2(new ListNode);
		sp1->_next = sp2;
		sp2->_prev = sp1;
	}
}
