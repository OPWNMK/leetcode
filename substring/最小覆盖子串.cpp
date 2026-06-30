#include "commen.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        int t_size = t.size();
        int s_size = s.size();
        unordered_map<char, int> t_count;
        for (int i = 0; i < t_size; ++i)
        {
            ++t_count[t[i]];
        }
        int left = 0;
        int right = 0;
        for (right = left; right < s_size; ++right)
        {
            
        }
        return s.substr(left,right - left);
    }
};