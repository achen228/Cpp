// list 的介绍及使用
// list是可以在常数范围内在任意位置进行插入和删除的序列式容器，并且该容器可以前后双向迭代
#include <iostream>
#include <list>
using namespace std;

void test_list1()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l) 
	{
		cout << e << " ";
	}
	cout << endl;
}
