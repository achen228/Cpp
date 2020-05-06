// vector 迭代器失效
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

	//auto ret = std::find(v.begin(), v.end(), 3);
	//v.erase(ret); // ret失效
	// 非法
	//++ret;
	//cout << *ret << endl;

	cout << v.capacity() << endl;
	auto ret = std::find(v.begin(), v.end(), 2);
	v.insert(ret, 20);
	cout << v.capacity() << endl;
}


void test_vector2() 
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	auto it = v.begin();
	while (it != v.end()) 
	{
		if (*it % 2 == 0) 
		{
			it = v.erase(it);
		}
		else 
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << endl;
	}
}

int main()
{
	test_vector2();

	system("pause");
	return 0;
}
