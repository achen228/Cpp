#pragma once
#include <iostream>
#include <vector>
#include <thread>
using namespace std;

namespace HungryMan
{
	//饿汉模式:一开始(main函数之前)就创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}

		Singleton(const Singleton&) = delete;
	private:
		Singleton()
		{}

		static Singleton _inst;
	};

	//static对象是在main函数之前创建的，这时只有主线程，所以不存在线程安全
	Singleton Singleton::_inst;

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
			vthreads.push_back(std::thread([]()
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
