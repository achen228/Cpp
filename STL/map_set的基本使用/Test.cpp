#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void Test()
{
	//排序+去重
	set<int> s;
	s.insert(9);
	s.insert(5);
	s.insert(2);
	s.insert(7);
	s.insert(5);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto pos = s.find(5);
	if (pos != s.end())
	{
		s.erase(pos);
	}
	s.erase(2);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> copy(s);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test1()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}

	map<int, int> copy(m);
	for (auto e : copy)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void Test2()
{
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	auto pos = m.find(2);
	if (pos != m.end())
	{
		m.erase(pos);
	}
	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}

	m.erase(1);
	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void Test3()
{
	string str[] = { "苹果", "香蕉", "西瓜", "苹果", "苹果", "香蕉", "西瓜", "苹果", "西瓜" };
	map<string, int> m;
	for (auto& e : str)
	{
		//m[e]++;

		pair<map<string, int>::iterator, bool> ret = m.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}

	for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void Test4()
{
	multiset<int> ms;
	ms.insert(9);
	ms.insert(5);
	ms.insert(5);
	ms.insert(2);
	ms.insert(7);
	for (auto& e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test5()
{
	multimap<string, int> mm;
	mm.insert(make_pair("奥迪", 60));
	mm.insert(make_pair("奔驰", 80));
	mm.insert(make_pair("奥迪", 60));
	mm.insert(make_pair("保时捷", 100));
	for (auto& e : mm)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	Test5();
	return 0;
}
