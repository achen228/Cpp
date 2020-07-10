//只出现一次的数字
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//说明：
//算法应该具有线性时间复杂度。不使用额外空间来实现。
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int val = 0;
        for (auto e : nums)
        {
            val ^= e;
        }
        return val;
    }
};
