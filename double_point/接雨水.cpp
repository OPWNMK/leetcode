#include "commen.h"

class Solution
{
public:
    /**
     * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图
     * 计算按此排列的柱子，下雨之后能接多少雨水。
     */
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = INT32_MIN;
        int maxRight = INT32_MIN;
        int ans = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] > maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    ans += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] > maxRight)
                {
                    maxRight = height[right];
                }
                else
                {
                    ans += maxRight - height[right];
                }
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