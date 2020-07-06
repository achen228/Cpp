//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        //使用映射的方式统计次数
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
