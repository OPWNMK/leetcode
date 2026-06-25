#include "commen.h"

class Solution
{
public:
    /**
     * @brief   给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
     *          满足 i != j、i != k 且 j != k ，
     *          同时还满足 nums[i] + nums[j] + nums[k] == 0 。
     *          请你返回所有和为 0 且不重复的三元组。
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        /**
         * first指针为三元组第一个元素，排序后的元素依次递增
         * 故可能有重复元素，遇到重复元素需要跳过
         * third指针为三元组第三个元素，若要让三元组为0
         * 则需要找出满足nums[second] + nums[third] = -nums[first]的元素
         * 
         */
        for (int first = 0; first < nums.size(); first++)
        {
            //跳过重复三元组
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int third = nums.size() - 1;
            int target = -nums[first];
            for (int second = first + 1; second < nums.size(); ++second)
            {
                //跳过重复元素
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                //若三元组相加大于0 则将third左移 （排序后数组升序排列）
                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }
                //当前first指向元素没有满足条件的三元组
                if (second == third)
                {
                    break;
                }
                if (nums[first] + nums[second] + nums[third] == 0)
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};