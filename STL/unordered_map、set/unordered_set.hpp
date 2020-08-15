#pragma once
#include "HashOpen.hpp"

namespace Unordered_Set
{
	template<class K>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename HashOpen<K, K, SetKeyOfT>::iterator iterator;
		iterator begin()
		{
			return _h.begin();
		}

		iterator end()
		{
			return _h.end();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _h.Insert(k);
		}
	private:
		HashOpen<K, K, SetKeyOfT> _h;
	};

	void test_unordered_set()
	{
		unordered_set<int> s;
		s.insert(1);
		s.insert(5);
		s.insert(4);
		s.insert(2);

		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
