#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;
	HashNode(const T& data)
		: _data(data)
		, _next(nullptr)
	{}
};

// 前置声明
template<class K, class T, class KeyOfT, class Hash>
class HashOpen;

template<class K, class T, class KeyOfT, class Hash>
struct __HashTableIterator
{
	typedef __HashTableIterator<K, T, KeyOfT, Hash> Self;
	typedef HashOpen<K, T, KeyOfT, Hash> HT;
	typedef HashNode<T> Node;
	Node* _node;
	HT* _pht;

	__HashTableIterator(Node* node, HT* pht)
		:_node(node)
		, _pht(pht)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	Self operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			// 如果一个桶走完了，找到下一个桶继续遍历
			KeyOfT koft;
			size_t i = _pht->HashFunc(koft(_node->_data)) % _pht->_table.size();
			++i;
			for (; i < _pht->_table.size(); i++)
			{
				Node* cur = _pht->_table[i];
				if (cur)
				{
					_node = cur;
					return *this;
				}
			}
			_node = nullptr;
		}
		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};

template<class K>
struct _Hash
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

template<>
struct _Hash<string>
{
	size_t operator()(const string& key)
	{
		//BKDR算法
		size_t hash = 0;
		for (size_t i = 0; i < key.size(); ++i)
		{
			hash *= 131;
			hash += key[i];
		}
		return hash;
	}
};

template<class K, class T, class KeyOfT, class Hash = _Hash<K>>
class HashOpen
{
	typedef HashNode<T> Node;
public:
	//迭代器中会用到私有_table，设置为友元
	friend struct __HashTableIterator < K, T, KeyOfT, Hash>;
	typedef __HashTableIterator<K, T, KeyOfT, Hash> iterator;

	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			if (_table[i])
			{
				return iterator(_table[i], this);
			}
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}
public:
	~HashOpen()
	{
		Clear();
	}

	void Clear()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			Node* cur = _table[i];
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_table[i] = nullptr;
		}
	}

	size_t HashFunc(const K& key)
	{
		Hash hash;
		return hash(key);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		KeyOfT koft;
		//如果负载因子==1，则扩容
		if (_num == _table.size())
		{
			vector<Node*> newTable;
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			newTable.resize(newSize);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					//重新计算data在newTable中的位置
					size_t index = HashFunc(koft(cur->_data)) % newTable.size();
					//将_table中的data搬移到newTable中
					Node* next = cur->_next;
					cur->_next = newTable[index];
					newTable[index] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newTable);
		}

		//检查data是否已经存在
		size_t index = HashFunc(koft(data)) % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (koft(cur->_data) == koft(data))
			{
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}
		//插入data
		Node* newNode = new Node(data);
		newNode->_next = _table[index];
		_table[index] = newNode;
		++_num;
		return make_pair(iterator(newNode, this), true);;
	}

	Node* Find(const K& key)
	{
		KeyOfT koft;
		size_t index = HashFunc(key) % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (koft(cur->_data) == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		KeyOfT koft;
		size_t index = HashFunc(key) % _table.size();
		Node* cur = _table[index];
		Node* prev = nullptr;
		while (cur)
		{
			if (koft(cur->_data) == key)
			{
				if (prev == nullptr)
				{
					_table[index] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}
				delete cur;
				return true;
			}
			prev = cur;
			cur = cur->_next;
		}
		return false;
	}
private:
	vector<Node*> _table;
	size_t _num = 0;
};
