#include "commen.h"

class Solution {
public:
    /**
     *  @brief  给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
                找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
                返回容器可以储存的最大水量
    */
    int maxArea(vector<int>& height) {
        /**
         * 木桶效应：能装多少水取决于短板
         * 容积 = min(height[left],height[right]) * (right - left)
         * 左指针指向数组开始，右指针指向末尾
         * 每次计算完容积后更新ans
         * 并且移动较小的一侧
         */
        int ans = 0;
        int left = 0;
        int right = height.size()- 1;
        while(left < right)
        {
            //计算容器宽度
            int wid = right - left;
            //计算当前容器高度
            int high = height[left] < height[right] ? height[left] : height[right];
            //计算当前容器容积
            int curArea = high * wid;
            ans = ans > curArea ? ans : curArea;
            // ans = max(ans,curArea);
            if(height[left] < height[right])
            {
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};