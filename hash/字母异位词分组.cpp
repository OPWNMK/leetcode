#include "commen.h"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> tmp_res;
        for(const auto&word:strs)
        {
            string key = word;
            sort(key.begin(),key.end());
            tmp_res[key].emplace_back(word);
        }
        for(const auto &value:tmp_res)
        {
            ans.push_back(value.second);
        }
        return ans;
    }
};