#include <memory>

// 创建出的类对象只能在堆上
// 思路:正常创建对象一定要调用构造函数，或者拷贝构造
class HeapOnly
{
public:
	static HeapOnly* GetObj()
	{
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}

	// C++98防拷贝:声明成私有
	//HeapOnly(const HeapOnly&);
public:
	// C++11:声明成delete
	HeapOnly(const HeapOnly&) = delete;
};

int main()
{
	//没有可用的构造函数，不能创建对象
	//HeapOnly hp;
	//HeapOnly* p = new HeapOnly;

	HeapOnly* p = HeapOnly::GetObj();
	std::shared_ptr<HeapOnly> sp1(HeapOnly::GetObj());
	std::shared_ptr<HeapOnly> sp2(HeapOnly::GetObj());

	//没有可用的拷贝构造函数
	//HeapOnly copy(*sp1);

	return 0;
}
