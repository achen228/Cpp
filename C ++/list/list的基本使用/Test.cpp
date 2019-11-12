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


void test_list2() 
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	list<int>::iterator pos = std::find(l.begin(), l.end(), 3);
	if (pos != l.end())
	{
		l.insert(pos, 30);
	}
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	pos = std::find(l.begin(), l.end(), 3);
	if (pos != l.end()) 
	{
		l.erase(pos);
	}
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	//// erase以后迭代器失效，不要再去访问pos
	//++pos;
	//cout << *pos << endl;
}


void test_list3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
		//it = l.erase(it);
		//l.erase(it++);
		if (*it % 2 == 0)
		{
			l.erase(it++);
		}
		else
		{
			++it;
		}
	}
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}


int main()
{
	test_list3();

	system("pause");
	return 0;
}
