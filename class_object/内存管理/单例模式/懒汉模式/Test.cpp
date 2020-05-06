// 懒汉模式
// 如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊，初始化网络连接啊，读取文件啊等等，
// 而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化，就会导致程序启动时非常的缓慢。 
// 所以这种情况使用懒汉模式（延迟加载）更好。
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。 
// 缺点：复杂
#include <iostream>
#include <thread> 
#include <mutex>
#include <atomic>
using namespace std; 

class Singleton 
{
public:
	// 线程安全
	static Singleton* GetInstance() 
	{
		if (_spinst == nullptr)  // 已经有实例对象以后，不在需要加锁
		{ 
			_smtx.lock();
			if (_spinst == nullptr)  // 没有实例对象时检查时，保证只有一个线程进去申请对象
			{
				_spinst = new Singleton;
			}
			_smtx.unlock();
		}

		return _spinst;
	}

	static void DelInstance() 
	{
		//_smtx.lock();
		if (_spinst != nullptr) 
		{
			delete _spinst;
			_spinst = nullptr;
		}
		//_smtx.unlock();
	}

private:
	Singleton() 
	{}

	//Singleton(const Singleton&);  // 防拷贝
	Singleton(const Singleton&) = delete;  // 防拷贝，C++11写法
	Singleton& operator=(const Singleton&) = delete;  // 防赋值，C++11写法

	static Singleton* _spinst;  // 单例对象指针
	static mutex _smtx;  // 互斥锁
};

Singleton* Singleton::_spinst = nullptr;
mutex Singleton::_smtx;

class GC 
{
public:
	~GC() 
	{
		Singleton::DelInstance();
	}
};

GC gc;

void func(int n, size_t* begin, size_t* end)
{
	*begin += clock();
	for (int i = 0; i < n; ++i)
	{
		Singleton::GetInstance();
	}
	*end += clock();
}

int main() 
{
	size_t begin = 0;
	size_t end = 0;
	size_t n = 1000000;
	thread t1(func, n, &begin, &end);
	thread t2(func, n, &begin, &end);
	thread t3(func, n, &begin, &end);
	thread t4(func, n, &begin, &end);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	cout << end - begin << endl;

	//thread t5(func, 10);
	//thread t6(func, 10);
	//t5.join();
	//t6.join();

	system("pause");
	return 0;
}
