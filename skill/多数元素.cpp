#include "commen.h"

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count_ = INT32_MIN;
        int ans;
        unordered_map<int, int> count;
        for (const int &num : nums)
        {
            if (count.find(num) == count.end())
            {
                count[num] = 1;
            }
            else
            {
                count[num]++;
            }
            if (count[num] > count_)
            {
                ans = num;
                count_ = count[num];
            }
        }
        return ans;
    }
    int majorityElement2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() / 2];
    }
};