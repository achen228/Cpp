#pragma once
#include <iostream>
#include <queue>
using namespace std;

template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& l, const T& r)
	{
		return l > r;
	}
};

template<class T, class Container = vector<T>, class Compare = Less<T>>
class PriorityQueue
{
public:
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		Compare com;
		while (child > 0)
		{
			//if (_con[child] > _con[parent])
			if (com(_con[parent], _con[child]))
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void AdjustDwon(size_t parent)
	{
		size_t child = parent * 2 + 1;
		Compare com;
		while (child < _con.size())
		{
			//if (child + 1 < _con.size()
			//	&& _con[child + 1] > _con[child])  
			if (child + 1 < _con.size()
				&& com(_con[child], _con[child + 1]))
			{
				++child;
			}

			//if (_con[child] > _con[parent])
			if(com(_con[parent], _con[child]))
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	void Push(const T& x)
	{
		_con.push_back(x);
		AdjustUp(_con.size() - 1);
	}

	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		AdjustDwon(0);
	}

	const T& Top()
	{
		return _con[0];
	}

	size_t Size() const
	{
		return _con.size();
	}

	bool Empty() const
	{
		return _con.empty();
	}
private:
	Container _con;
};
