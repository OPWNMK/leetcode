#include "commen.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 复杂度为O(nlogn)不符合要求
        //  sort(nums.begin(), nums.end());
        //  for (int i = 0; i < nums.size(); i += 2)
        //  {
        //      if (i == nums.size() - 1 || nums[i] != nums[i + 1])
        //          return nums[i];
        //  }
        //  return -1;
        int ans = 0;
        for (const int &num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};