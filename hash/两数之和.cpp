#include "commen.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /**
         * 将nums存入一个map中
         * key 对应 nums[i]
         * value 对应 index
         * 寻找target - num 在map中存不存在
         */
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size();i++)
        {
            auto it = map.find(target - nums[i]);
            if(it != map.end())
            {
                return {it->second,i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};