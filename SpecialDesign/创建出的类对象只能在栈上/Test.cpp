// 创建出的类对象只能在栈上
class StackOnly
{
public:
	static StackOnly GetObj()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};

int main()
{
	//没有可用的构造函数，不能创建对象
	//StackOnly so;
	//StackOnly* p = new StackOnly;

	StackOnly st = StackOnly::GetObj();

	return 0;
}

// 这种方案存在一定程序缺陷，无法阻止在数据段(静态区)创建对象
//class StackOnly
//{
//public:
//	void* operator new(size_t size) = delete;
//};
//
//int main()
//{
//	static StackOnly st;
//	return 0;
//}
