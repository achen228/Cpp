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


template<class T>
class List 
{
	typedef ListNode<T> Node;
public:
	typedef __ListIterator<T, T&, T*> iterator;
	typedef __ListIterator<T, const T&, const T*> const_iterator;

	List()
		:_head(new Node)
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	// copy(l)  拷贝构造
	List(const List<T>& l) 
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		for (auto e : l)
		{
			PushBack(e);
		}
	}

	// 赋值
	List<T>& operator=(List<T> l)
	{
		swap(_head, l._head);
		return *this;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	// 清理数据
	void Clear() 
	{
		iterator it = begin();
		while (it != end())
		{
			//it = Erase(it);
			Erase(it++);
		}
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	// 尾插
	void PushBack(const T& x) 
	{
		Node* tail = _head->_prev;
		Node* newnode = new Node(x);

		tail->_next = newnode;
		newnode->_prev = tail;

		newnode->_next = _head;
		_head->_prev = newnode;

		//Insert(end(), x);
	}

	// 头插
	void PushFront(const T& x)
	{
		Insert(begin(), x);
	}

	// 尾删
	void PopBack()
	{
		Erase(--end());
	}

	// 头删
	void PopFront() 
	{
		Erase(begin());
	}

	// 在pos前插入
	void Insert(iterator pos, const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);

		prev->_next = newnode;
		newnode->_prev = prev;

		newnode->_next = cur;
		cur->_prev = newnode;
	}

	// 删除pos所在结点
	iterator Erase(iterator pos)
	{
		assert(pos._node != _head);
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;

		delete cur;
		return iterator(next);
	}

	size_t Size() 
	{
		size_t size = 0;
		for (auto e : *this) 
		{
			++size;
		}
		return size; 
	}

	bool Empty() 
	{
		return _head->_next = _head;
	}

private:
	Node* _head;
};

struct AA 
{
	int _a1;
	int _a2;
};
