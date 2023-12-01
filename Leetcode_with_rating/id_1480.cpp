/*
# 1480. 一维数组的动态和
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

 

示例 1：

输入：nums = [1,2,3,4]
输出：[1,3,6,10]
解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：[1,2,3,4,5]
解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
示例 3：

输入：nums = [3,1,2,10,1]
输出：[3,4,6,16,17]
 

提示：

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6

此题使用求和公式暴力求解的效率较低，因为包含大量重复计算。考虑借助「前一个动态和 f(i−1)f(i-1)f(i−1) 」来计算得到「当前动态和 f(i)f(i)f(i) 」，此题被约化为一个简单动态规划问题。

作者：Krahets
链接：https://leetcode.cn/problems/running-sum-of-1d-array/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
#include <typeinfo>
using std::vector;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = temp + nums[i];
            ans.push_back(temp);
        }
        return ans;
    }
};