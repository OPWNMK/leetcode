#include "commen.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN;
        int temp;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            temp = sum + nums[i];
            sum = temp > nums[i] ? temp : nums[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
};