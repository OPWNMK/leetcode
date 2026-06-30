#include "commen.h"

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int ans = 0;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = nums[i];
        }
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j >= 0; --j)
            {
                sum += arr[j];
                if (sum == k)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};