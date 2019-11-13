// list 的模拟实现
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
struct ListNode
{
	ListNode<T>* _next;
	ListNode<T>* _prev;
	T _data;

	ListNode(const T& x = T())
		:_next(nullptr)
		, _prev(nullptr)
		, _data(x)
	{}
};

template<class T, class Ref, class Ptr>
struct __ListIterator 
{
	typedef ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	__ListIterator(Node* node)
		:_node(node)
	{}

	// *it;
	Ref operator*() 
	{
		return _node->_data;
	}

	// it->
	Ptr operator->() 
	{
		return &_node->_data;
	}

	Self& operator++()  // 前置++
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)  // 后置++
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()  // 前置--
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)  // 后置--
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	// it1 != it2
	bool operator!=(const Self& it) 
	{
		return _node != it._node;
	}

	// it1 == it2
	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
};
