#include "commen.h"

class Solution
{
public:
    /**
     * @brief   给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
     *          异位词的字母是一样的，故排序后的结果相同
     *          将排序后的单词作为map的key
     *          将原有单词作为value存入map
     *          value使用vector存储
     *          然后将map的value存入ans
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> tmp_res;
        for (const auto &word : strs)
        {
            string key = word;
            sort(key.begin(), key.end());
            tmp_res[key].emplace_back(word);
        }
        for (const auto &value : tmp_res)
        {
            ans.push_back(value.second);
        }
        return ans;
    }
};