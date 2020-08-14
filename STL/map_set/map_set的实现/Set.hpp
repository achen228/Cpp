#pragma once
#include "RBTree.hpp"

namespace Set
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
	public:
		pair<iterator, bool> Insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator Find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void TestSet()
	{
		set<int> s;
		s.Insert(3);
		s.Insert(4);
		s.Insert(1);
		s.Insert(2);
		s.Insert(5);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;

		set<int>::iterator pos = s.Find(3);
		if (pos != s.end())
		{
			cout << *pos << endl;
		}
	}
}
