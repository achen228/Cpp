#pragma once
#include "HashOpen.hpp"

namespace Unordered_Map
{
	template<class K, class V>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashOpen<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		iterator begin()
		{
			return _h.begin();
		}

		iterator end()
		{
			return _h.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _h.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _h.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		HashOpen<K, pair<K, V>, MapKeyOfT> _h;
	};

	void test_unordered_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("left", "左边"));
		dict.insert(make_pair("string", "字符串"));
		dict["left"] = "修改左边";
		dict["end"] = "尾部";

		//unordered_map<string, string>::iterator it = dict.begin();
		auto it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
