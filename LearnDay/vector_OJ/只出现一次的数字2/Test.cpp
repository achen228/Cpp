//只出现一次的数字2
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
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
        int bitsArr[32] = { 0 };
        //统计出所有数32个位出现1的次数
        for (auto e : nums)
        {
            for (size_t i = 0; i < 32; ++i)
            {
                if (e & (1 << i))
                {
                    bitsArr[i]++;
                }
            }
        }

        int val = 0;
        for (size_t i = 0; i < 32; ++i)
        {
            //次数为3n+1的位就是只出现一次的数为1的位
            if (bitsArr[i] % 3 == 1)
            {
                val |= (1 << i);
            }
        }
        return val;
    }
};
