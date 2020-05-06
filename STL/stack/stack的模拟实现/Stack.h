#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

template<class T, class Container = deque<int>>
class Stack 
{
public:
	void Push(const T& x) // 插入
	{
		_con.push_back(x);
	}

	void Pop()  // 删除
	{
		_con.pop_back();
	}

	size_t Size() const
	{
		return _con.size();
	}

	bool Empty() const 
	{
		return _con.empty();
	}

	T& Top()  // 弹出
	{
		return _con.back();
	}

	const T& Top() const 
	{
		return _con.back();
	}

private:
	Container _con;
};
