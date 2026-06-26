#include "commen.h"

class Solution
{
public:
    /**
     * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图
     * 计算按此排列的柱子，下雨之后能接多少雨水。
     */
    int trap(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        
        // 这两个变量记录的是：从最左端到 left 位置，遇到的最大高度；
        // 以及从最右端到 right 位置，遇到的最大高度。
        int maxLeft = INT32_MIN;
        int maxRight = INT32_MIN;
        int ans = 0;

        // 只要左右指针没碰头，就不断向中间逼近
        while (left < right) {
            // 【核心判断】：哪边当前的柱子低，就先处理哪边（短板原理）
            if (height[left] < height[right]) {
                
                // 情况 1：当前 left 柱子比左边最大还高
                // 那么这里形不成凹槽（水会流走），不积水，只更新最高记录
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } 
                // 情况 2：当前 left 柱子比左边最高低
                // 此时左边有挡板（maxLeft），右边有挡板（因为 height[right] 比当前高）
                // 所以当前柱子能接的水量 = 左边最高 - 自己高度
                else {
                    ans += maxLeft - height[left];
                }
                // 处理完了左侧当前格子，指针右移
                left++;
            } 
            else { // 当 height[left] >= height[right] 时，说明右侧是短板，处理右边
                // 同理：如果当前 right 柱子比右边最大还高，更新记录，不积水
                if (height[right] > maxRight) {
                    maxRight = height[right];
                } 
                // 否则，当前右侧柱子能接的水 = 右边最高 - 自己高度
                else {
                    ans += maxRight - height[right];
                }
                // 处理完了右侧当前格子，指针左移
                right--;
            }
        }
        return ans;
    }

    int trap2(vector<int> &height)
    {
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < height.size();i++)
        {
            while(!stk.empty() && height[i] > height[stk.top()])
            {
                int top = stk.top();
                stk.pop();
                if(stk.empty())
                {
                    break;
                }
                int left = stk.top();
                ans += (i - left - 1 ) * (min(height[left],height[i]) - height[top]);
            }
            stk.push(i);
        }
        return ans;
    }
    
};