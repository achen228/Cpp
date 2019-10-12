// 单例模式
// 一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全局
// 访问点，该实例被所有程序模块共享。比如在某个服务器程序中，该服务器的配置信息存放在一个文件中，这
// 些配置数据由一个单例对象统一读取，然后服务进程中的其他对象再通过这个单例对象获取这些配置信息，这
// 种方式简化了在复杂环境下的配置管理。

// 单例模式有两种：饿汉模式和懒汉模式


// 饿汉模式：就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象。
// 优点：简单 
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定
#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		static Singleton sinst;
		return &sinst;
	}

private:
	Singleton() 
	{}

	// Singleton(const Singleton&);  // 防拷贝
	Singleton(const Singleton&) = delete;  // C++11中防拷贝
};

int main() 
{
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	system("pause");
	return 0;
}
