#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

namespace LazyMan
{
	// 懒汉模式:第一次获取对象时，再创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			// 双检查
			//提升代码性能，避免每次都要去加锁解锁
			if (_pinst == nullptr)
			{
				//多线程情况下可能会出现同时创建对象的场景
				//_mtx.lock();
				unique_lock<mutex> lock(_mtx);
				if (_pinst == nullptr)
				{
					_pinst = new Singleton;
				}
				//_mtx.unlock();
			}
			return _pinst;
		}

		static void DelInstance()
		{
			//如果使用GC自动析构，此时不加锁，main函数结束后多线程也已经结束
			//如果是手动释放，需要加锁，main函数未结束，多线程存在，避免销毁对象的时候其它线程创建对象
			//unique_lock<mutex> lock(_mtx);
			delete _pinst;
			_pinst = nullptr;
		}

		Singleton(const Singleton& s) = delete;

	private:
		Singleton()
		{}

		static Singleton* _pinst;
		static mutex _mtx;
	};

	//静态成员的定义
	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;

	// 1、如果要手动释放单例对象，可以调用DelInstance
	// 2、如果需要程序结束时，正常释放单例对象，可以加入下面的设计
	class GC
	{
	public:
		~GC()
		{
			Singleton::DelInstance();
		}
	};

	//定义GC的全局静态对象，main函数结束后，调用它的析构函数
	static GC gc;

	void Test1()
	{
		//没有可用的构造函数，不能创建对象
		//Singleton s1;
		//Singleton s2;

		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;
		cout << Singleton::GetInstance() << endl;

		//没有可用的拷贝构造函数
		//Singleton copy(*Singleton::GetInstance());
	}

	void Test2()
	{
		vector<thread> vthreads;
		int n = 10;
		for (int i = 0; i < n; ++i)
		{
			vthreads.push_back(thread([]()
			{
				cout << this_thread::get_id() <<":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthreads)
		{
			t.join();
		}
	}
}
