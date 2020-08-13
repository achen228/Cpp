#include <vector>
//前K个高频单词
//给一非空的单词列表，返回前 k 个出现次数最多的单词。
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
class Solution
{
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		//map中按照key排序，即已经按照字母顺序将单词排序完成，并且统计出了单词出现的频率次数
		map<string, int> countMap;
		for (auto& e : words)
		{
			countMap[e]++;
		}

		//1.可以用sort排序，针对单词出现的频率次数，但是sort排序不稳定，可能会将排序好的字母顺序打乱
		//2.用multimap排序，允许key重复，且出现频率次数相同的单词会按照map中的字母顺序排列在multimap中
		//  因为要找到前k个出现次数最多的单词，则按照降序排列方便后面的查找，使用仿函数greater
		multimap<int, string, greater<int>> sortMap;
		for (auto& e : countMap)
		{
			sortMap.insert(make_pair(e.second, e.first));
		}

		//在multimap中找到前k个出现次数最多的单词，保存在vector<string>中
		vector<string> v;
		for (auto& e : sortMap)
		{
			if (k == 0)
			{
				break;
			}
			v.push_back(e.second);
			--k;
		}

		return v;
	}
};
