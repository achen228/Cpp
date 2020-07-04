#pragma once
#include <iostream>
#include <cassert>
using namespace std;

namespace MakeList
{
	template<class T>
	struct ListNode
	{
		ListNode* _prev;
		ListNode* _next;
		T _data;
		ListNode(const T& data = T())
			: _prev(nullptr)
			, _next(nullptr)
			, _data(data)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListIterator<T, Ref, Ptr> Self;
		typedef ListNode<T> Node;
		Node* _node;

		ListIterator(Node* node)
			: _node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(Self it)
		{
			return _node != it._node;
		}

		bool operator==(Self it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
	private:
		typedef ListNode<T> Node;
	public:
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

		list()
			: _head(nullptr)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//拷贝构造
		list(const list<T>& l)
			: _head(nullptr)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (auto e : l)
			{
				push_back(e);
			}
		}

		//赋值运算符传统写法
		//list<T>& operator=(const list<T>& l)
		//{
		//	if (this != &l)
		//	{
		//		clear();
		//		for (auto e : l)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		//赋值运算符现代写法
		list<T>& operator=(list<T> l)
		{
			std::swap(_head, l._head);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		void push_back(const T& val)
		{
			Node* tail = _head->_prev;
			Node* new_node = new Node(val);
			tail->_next = new_node;
			new_node->_prev = tail;
			_head->_prev = new_node;
			new_node->_next = _head;
		}

		void pop_back()
		{
			assert(_head->_prev != nullptr);
			Node* tail = _head->_prev;
			Node* prev = tail->_prev;
			delete tail;
			_head->_prev = prev;
			prev->_next = _head;
		}

		void push_front(const T& val)
		{
			Node* cur = _head->_next;
			Node* new_node = new Node(val);
			_head->_next = new_node;
			new_node->_prev = _head;
			new_node->_next = cur;
			cur->_prev = new_node;
		}

		void pop_front()
		{
			assert(_head->_next != nullptr);
			Node* cur = _head->_next;
			Node* next = cur->_next;
			delete cur;
			_head->_next = next;
			next->_prev = _head;
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* new_node = new Node(val);
			prev->_next = new_node;
			new_node->_prev = prev;
			new_node->_next = cur;
			cur->_prev = new_node;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			delete cur;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
	private:
		Node* _head;
	};
}
