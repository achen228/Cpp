//只出现一次的数字3
//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素。
//说明：
//算法应该具有线性时间复杂度。仅使用常数额外空间来实现。
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //val为只出现一次的两个数字异或的结果
        int val = 0;
        for (auto e : nums)
        {
            val ^= e;
        }

        //找出val的32位中某一位是1的位置
        size_t i = 0;
        for (; i < 32; i++)
        {
            if (val & (1 << i))
            {
                break;
            }
        }

        //将原数组中该位置是1的分一组，是0的分另一组
        int num1 = 0, num2 = 0;
        for (auto e : nums)
        {
            if (e & (1 << i))
            {
                num1 ^= e;
            }
            else
            {
                num2 ^= e;
            }
        }

        //将这两个只出现一次的数字保存到vector中返回
        vector<int> v;
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};
