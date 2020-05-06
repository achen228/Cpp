#pragma once
#include <iostream>
#include <queue>
#include <list>
using namespace std;

template<class T, class Container = deque<int>>
class Queue 
{
public:
	void Push(const T& x) 
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_front();
	}

	size_t Size() const
	{
		_con.size();
	}

	bool Empty() const
	{
		return _con.empty();
	}

	const T& Front()
	{
		return _con.front();
	}

	const T& Back()
	{
		return _con.back();
	}
private:
	Container _con;
};
