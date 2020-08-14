#pragma once
#include <iostream>
using namespace std;

//节点的颜色
enum Color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;  //左孩子
	RBTreeNode<T>* _right; //右孩子
	RBTreeNode<T>* _parent;//双亲
	T _data;
	Color _col; //红黑颜色限制, 新插入节点默认为红色
	RBTreeNode(const T& data, Color col = RED)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(col)
	{}
};

template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeIterator<T, Ref, Ptr> Self;
	typedef RBTreeNode<T> Node;
	Node* _node;
	RBTreeIterator(Node* node)
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

	Self& operator++()
	{
		if (_node->_right)
		{
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}
			_node = subLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};


template<class K, class T, class KOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T, T&, T*> iterator;
	typedef RBTreeIterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return nullptr;
	}
public:
	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		KOfT koft;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (koft(data) > koft(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (koft(data) < koft(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newNode = cur;
		cur->_col = RED;
		if (koft(data) > koft(parent->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//检测红黑树的性质
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//情况一：uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else //情况二/三：uncle不存在或uncle存在且为黑
				{
					//情况三双旋后变单旋，成为情况二
					if (cur == parent->_right)
					{
						RotateL(parent);
						//交换的是节点的指针，不是节点
						swap(cur, parent);
					}

					//处理情况二
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					//调整结束
					break;
				}
			}
			else //parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newNode), true);;
	}

	iterator Find(const K& key)
	{
		KOfT koft;
		Node* cur = _root;
		while (cur)
		{
			if (key > koft(cur->_data))
			{
				cur = cur->_right;
			}
			else if (key < koft(cur->_data))
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}
		return iterator(nullptr);
	}
private:
	//左单旋
	void RotateL(Node* parent)
	{
		Node* pParent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == pParent->_left)
			{
				pParent->_left = subR;
			}
			else
			{
				pParent->_right = subR;
			}
			subR->_parent = pParent;
		}
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* pParent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == pParent->_left)
			{
				pParent->_left = subL;
			}
			else
			{
				pParent->_right = subL;
			}
			subL->_parent = pParent;
		}
	}
private:
	Node* _root = nullptr;
};
