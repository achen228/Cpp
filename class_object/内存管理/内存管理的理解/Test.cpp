// （一）C/C++内存分布

//1. 栈又叫堆栈，非静态局部变量 / 函数参数 / 返回值等等，栈是向下增长的。 
//2. 内存映射段是高效的I / O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口创建共享内存，
//   做进程间通信。（Linux） 
//3. 堆用于程序运行时动态内存分配，堆是可以上增长的。 
//4. 数据段--存储全局数据和静态数据。 
//5. 代码段--可执行的代码 / 只读常量。

// （二）C++内存管理方式
// C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力而且使用起来比较麻烦，
// 因此C++又提出了自己的内存管理方式：通过new和delete操作符进行动态内存管理

//注意：申请和释放单个元素的空间，使用new和delete操作符，申请和释放连续的空间，使用new[]和 delete[]
//注意：在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc与free不会

// （三）operator new 和operator delete函数
//new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是系统提供的
//全局函数，new在底层调用operator new全局函数来申请空间，delete在底层通过operator delete全局函数
//来释放空间

// operator new 实际也是通过malloc来申请空间，如果malloc申请空间成功就直接返回，
// 否则执行用户提供的空间不足应对措施，如果用户提供该措施就继续申请，否则就抛异常。
// operator delete 最终是通过free来释放空间的

// new		operator new + 调用构造函数
// delete	调用析构函数 + operator delete


// （四）定位new表达式(placement-new)
// 定位new表达式是在已分配的原始内存空间中调用构造函数初始化一个对象。
// 使用场景：
//		定位new表达式在实际中一般是配合内存池使用。因为内存池分配出的内存没有初始化，
//		所以如果是自定义类型的对象，需要使用new的定义表达式进行显示调构造函数进行初始化。
#include <iostream>
using namespace std;

class Test
{
public:   
	Test() 
		: _data(0)
	{ 
		cout << "Test():" << this << endl; 
	}

	~Test()
	{ 
		cout << "~Test():" << this << endl; 
	}   
private:   
	int _data;
};

int main() 
{
	Test* p1 = new Test;
	delete p1;

	Test* p2 = (Test*)operator new(sizeof(Test));
	new(p2)Test();  // 对已有空间显示调用构造函数的方式

	p2->~Test();
	operator delete (p2);

	system("pause");
	return 0;
}

// （五）内存泄漏
//内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，
//        而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。
//内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应
//越来越慢，最终卡死。

//堆内存泄漏(Heap leak)
//  堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，
//  用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以
//  后这部分空间将无法再被使用，就会产生Heap Leak。 
//系统资源泄漏
//  指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，
//  严重可导致系统效能减少，系统执行不稳定。
