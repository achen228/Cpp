// vector 的使用
// vector 是一个能够存放任意类型的动态数组，能够增加和压缩数据
// 必须包含头文件 #inlcude <vector>
#include <iostream>
#include <vector>
using namespace std;

void test_vector1() 
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i) 
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) 
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	for (auto e : v) 
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector2()
{
	// vector 的增容   VS中1.5倍增长   Linux中2倍增长
	size_t sz;
	vector<int> foo;
	//foo.resize(100);
	sz = foo.capacity();
	cout << "making foo grow:" << endl;
	for (int i = 0; i < 100; ++i) 
	{
		foo.push_back(i);
		if (sz != foo.capacity()) 
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}


	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.insert(v.begin(), 0);

	for (auto e : v) 
	{
		cout << e << " ";
	}
	cout << endl;

	// 在2前面插入20
	auto pos = find(v.begin(), v.end(), 2);
	if (pos != v.end()) 
	{
		v.insert(pos, 20);
	}

	// 将2删除
	pos = find(v.begin(), v.end(), 2);
	v.erase(pos);

	for (auto e : v) 
	{
		cout << e << " ";
	}
	cout << endl;

	//v.clear();  // 清理数据，但不会释放空间
	//v.~vector(); // 显示的调用析构函数->释放空间->不推荐

	{	// 局部域，tmp->局部对象
		vector<int> tmp;  // 通过交换释放空间->推荐
		tmp.swap(v);      // swap(tmp, v);->代价大，拷贝构造等
	}

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


int main()
{
	test_vector2();

	system("pause");
	return 0;
}
