// malloc/free和new/delete的区别
// malloc/free和new/delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。
// 不同点：
//1. malloc和free是函数，new和delete是操作符 
//2. malloc申请的空间不会初始化，new可以初始化 
//3. malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可 
//4. malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型 
//5. malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常 
//6. 申请自定义类型对象时，malloc / free只会开辟空间，不会调用构造函数与析构函数，
//   而new在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数
//   完成空间中资源的清理

// new delete malloc free 用法
#include <iostream>
using namespace std;

class A 
{
public:
	A(int a = 0) 
	{
		_a = a;
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

int main() 
{
	// 基本类型、内置类型
	// 动态申请单个对象
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	free(p1);
	delete p2;

	// 动态申请N个对象
	int* p3 = (int*)malloc(sizeof(int)*10);
	int* p4 = new int[10];
	free(p3);
	delete[] p4;


	// 自定义类型
    // 动态申请单个对象
	A* p5 = (A*)malloc(sizeof(A)); // 开空间
	A* p6 = new A; // 开空间+调构造函数初始化

	free(p5);  // 释放空间
	delete p6; // 析构函数 + 释放空间

	// 动态申请N个对象
	A* p7 = (A*)malloc(sizeof(A)*10); // 开空间
	A* p8 = new A[10]; // 开空间+调构造函数初始化

	free(p7);	  // 释放空间
	delete[] p8; // 析构函数 + 释放空间

	system("pause");
	return 0;
}
