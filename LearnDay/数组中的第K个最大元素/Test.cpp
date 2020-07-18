//数组中的第K个最大元素
//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//示例 1:
//    输入: [3, 2, 1, 5, 6, 4] 和 k = 2
//    输出 : 5
//示例 2 :
//    输入 : [3, 2, 3, 1, 2, 4, 5, 5, 6] 和 k = 4
//    输出 : 4
//说明 :
//    你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        //时间复杂度：O(N*logN)
        //空间复杂度：O(N)
        //priority_queue<int> pq(nums.begin(), nums.end());
        //while (--k)
        //{
        //    pq.pop();
        //}
        //return pq.top();


        //时间复杂度：O(N*logN)
        //空间复杂度：O(1)
        //sort(nums.begin(), nums.end());
        //return nums[nums.size() - k];

        
        //当遇到海量数据，N很大，K很小时，如下效率就很高
        //时间复杂度：O(N*logK)
        //空间复杂度：O(K)
        //建小堆
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int i = 0;
        for (; i < k; ++i)
        {
            minHeap.push(nums[i]);
        }

        for (; i < nums.size(); ++i)
        {
            if (nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};
