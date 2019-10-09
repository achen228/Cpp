// 实现对象只能在栈上
// 只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可
#include <iostream>
using namespace std;

class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);    
	void operator delete(void* p);
};

int main() 
{
	StackOnly p;

	system("pause");
	return 0;
}
