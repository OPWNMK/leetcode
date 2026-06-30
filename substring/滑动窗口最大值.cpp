#include "commen.h"

class Solution {
public:
    /**
     * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
     * 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
     */

     /**
      * @brief  超时算法，时间复杂度O(nk)
      */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        vector<int> ans;
        /**
         * 维护一个窗口内最大值下标max_index
         * 若   max_index < left 则说明已经窗口已经移出范围
         * 需重新判断max,与max_index
         * 若在窗口范围内，则判断nums[right]与max的值
         */
        int max_index = -1;
        int max_ = INT32_MIN;
        int left = 0,right = k-1;
        for(int i = left;i <= right;++i)
        {
            if(nums[i] > max_)
            {
                max_ = nums[i];
                max_index = i;
            }
        }
        ans.emplace_back(max_);
        ++left;
        ++right;
        while(right < nums.size())
        {
            if(max_index < left)
            {
                max_ = INT32_MIN;
                for(int i = left;i <= right;++i)
                {
                    if(nums[i] > max_)
                    {
                        max_ = nums[i];
                        max_index = i;
                    }
                }
            }
            else
            {
                max_ = max(max_,nums[right]);
                max_index = max_ > nums[right] ? max_index : right;    
            }
            ans.emplace_back(max_);
            ++left;
            ++right;
        }
        return ans;
    }
    
    /**
     * @brief   优先队列
     *          优先队列底层为一个堆，默认堆顶元素为最大元素
     *          先将前k个元素以及下标入队
     *          然后从第k个元素依次将元素入队
     *          再判断最大元素是否还在窗口内，如果不在则将其移出队列
     *          队列会将第二个最大元素移动到堆顶
     *          最后将队首元素存入ans
     */
    vector<int> maxSlidingWindow2(vector<int>& nums, int k)
    {
        priority_queue<pair<int,int>> queue;
        vector<int> ans;
        for(int i = 0;i < k;++i)
        {
            queue.emplace(nums[i],i);
        }
        ans.push_back(queue.top().first);
        for(int i = k; i < nums.size(); ++i)
        {
            queue.emplace(nums[i],i);
            while(queue.top().second <= i - k)
            {
                queue.pop();
            }
            ans.push_back(queue.top().first);
        }
        return ans;
    }

    /**
     * @brief 单调队列
     *        队列中维护所有可能窗口最大值元素的下标
     *        队列中元素按照nums的大小排列
     *        当队尾元素不大于新元素时将其移除
     *        队首元素即为最大值元素的下标
     *        若队首元素已经不在窗口中，将其弹出
     */
    vector<int> maxSlidingWindow3(vector<int> &nums, int k) {
        int n = nums.size();
        deque<int> q;      // 存储下标，维护单调递减（队首最大）
        vector<int> ans;

        // 1. 初始化第一个窗口
        for (int i = 0; i < k; ++i) {
            // 只要队尾元素 <= 新元素，队尾就永无出头之日（值小且下标旧），踢掉
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        // 2. 滑动剩余窗口
            for (int i = k; i < n; ++i) {
            // 移除队列中所有不如 nums[i] 有竞争力的旧元素（值更小或相等，且下标更旧）
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);

            // 移除所有下标已滑出当前窗口（左边界为 i - k + 1）的队首过期元素
            // 当前窗口有效索引范围：[i - k + 1, i]，因此 idx <= i - k 即为过期
            while (q.front() <= i - k) {
                q.pop_front();
            }

            // 此时队首即为当前窗口最大值
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};