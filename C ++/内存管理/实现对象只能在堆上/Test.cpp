// 实现对象只能在堆上
// 1. 将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。 
// 2. 提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
#include <iostream>
using namespace std;

class HeapOnly 
{
public:
	static HeapOnly* GetHeapObj() 
	{
		return new HeapOnly;
	}
private:
	HeapOnly() 
	{}
};

int main()
{
	//HeapOnly ho;  // 对象在栈上
	//HeapOnly* p = new HeapOnly; // 对象在堆上

	HeapOnly* p = HeapOnly::GetHeapObj();

	HeapOnly copy(*p);  // 缺陷：拷贝构造，对象在栈上

	system("pause");
	return 0;
}
