#include "commen.h"

class Solution
{
public:
    /**
     * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
     */
    void moveZeroes(vector<int> &nums)
    {
        /**
         * 用left记录下一个非零元素的位置
         * 遍历，遇到非零元素就放到left，left++
         * 将left之后的所有位置置为0
         */
        int left = 0;
        for (const int &num : nums)
        {
            if (num != 0)
            {
                nums[left] = num;
                left++;
            }
        }
        while(left < nums.size())
        {
            nums[left] = 0;
            left++;
        }
    }
};