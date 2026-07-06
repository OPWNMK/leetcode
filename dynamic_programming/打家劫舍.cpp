#include "commen.h"

class Solution
{
public:
    /**
     * 你是一个专业的小偷，计划偷窃沿街的房屋。
     * 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
     * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
     * 给定一个代表每个房屋存放金额的非负整数数组，
     * 计算你不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
     */
    int rob(vector<int> &nums)
    {
        if(nums.empty())
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        /**
         * 利用滚动数组，
         * first存储前一个数据
         * second存储其后面的数据
         * 如果first+ nums[i] > second则偷，并更新second 否则不偷
         * 然后将更新first
         */
        int first = nums[0],second = max(first,nums[1]);
        for(int i = 2;i < nums.size();++i)
        {
            int temp = second;
            second = max(first + nums[i],second);
            first = temp;
        }
        return second;
    }
};