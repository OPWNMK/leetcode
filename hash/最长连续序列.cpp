#include "commen.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        
        int cur_len = 1;
        int max_len = 1;
        int prev = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int cur = nums[i];
            if (cur == prev) {
                // 重复数字，跳过
                continue;
            } else if (cur == prev + 1) {
                // 连续，长度+1
                cur_len++;
            } else {
                // 不连续，更新最大值，重置当前长度
                max_len = max(max_len, cur_len);
                cur_len = 1;
            }
            //更新前一个连续元素
            prev = cur;
        }
        // 循环结束后再更新一次，处理数组整体连续的情况
        max_len = max_len > cur_len ? max_len : cur_len;
        return max_len;
    }
    /*
        官方题解
        先对nums去重
        对于每个数，判断其是否是序列的开头
        如果是则cur - 1 不存在，
        如果存在cur - 1 则当前数字不是序列的开头
        如果当前数字是序列的开头
        那么cur + 1一定存在
        当cur+1存在时不断更新cur和curLenth最终即可得到最长子序列长度
    */
   int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        //去除nums中的重复元素
        for(const int& num: nums)
        {
            nums_set.insert(num);
        }
        //最长序列长度
        int longestStreak = 0;
        for(const int& num:nums_set)
        {
            //跳过不是序列开头的数字
            if(!nums_set.count(num-1))
            {
                int currentNum = num;
                int currentStreak = 1;
                while(nums_set.count(currentNum + 1))
                {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = longestStreak > currentStreak ? longestStreak : currentStreak;
            }
        }
        return longestStreak;
   }
};