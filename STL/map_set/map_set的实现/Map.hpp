#pragma once
#include "RBTree.hpp"

namespace Map
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
	public:
		pair<iterator, bool> Insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
		}

		iterator Find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void TestMap()
	{
		map<int, int> m;
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(3, 3));
		m.Insert(make_pair(5, 5));
		m.Insert(make_pair(2, 2));
		m.Insert(make_pair(4, 4));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto e : m)
		{
			cout << e.first << ":" << e.second << endl;
		}
		cout << endl;

		map<int, int>::iterator pos = m.Find(4);
		if (pos != m.end())
		{
			cout << pos->first << ":" << pos->second << endl;
		}
		cout << endl;
	}

	void TestMapCount()
	{
		string str[] = { "苹果", "香蕉", "西瓜", "苹果", "苹果", "香蕉", "西瓜", "苹果", "西瓜" };
		map<string, int> m;
		for (auto& e : str)
		{
			m[e]++;
			//pair<map<string, int>::iterator, bool> ret = m.Insert(make_pair(e, 1));
			//if (ret.second == false)
			//{
			//	ret.first->second++;
			//}
		}

		for (auto e : m)
		{
			cout << e.first << ":" << e.second << endl;
		}
		cout << endl;
	}
}
