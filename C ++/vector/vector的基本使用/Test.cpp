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
