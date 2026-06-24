#include "commen.h"

class Solution
{
public:
    void backtrack(int first, int len, vector<int> &output, vector<vector<int>> &res)
    {
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i)
        {
            swap(output[i], output[first]);
            backtrack(first+1, len, output, res);
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        backtrack(0, nums.size(), nums, ans);
        return ans;
    }
};