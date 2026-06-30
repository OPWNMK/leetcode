#include "commen.h"

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int start = 0;
        int ans = 0;
        unordered_map<char, int> count;
        for (start = 0; start < n; ++start)
        {
            for (int end = start; end < n; ++end)
            {
                ++count[s[end]];
                if (count['a'] != 0 && count['b'] != 0 && count['c'] != 0)
                {
                    ans += n - end + 1;
                    count.clear();
                }
            }
        }
        return ans;
    }
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int left = 0;
        vector<int> count(3, 0);
        int ans = 0;
        for (int right = 0; right < n; ++right)
        {
            ++count[s[right] - 'a'];
            // 当窗口内三个字符都齐了，就收缩左边界
            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
            {
                // 此时，以 left 为起点，right 为终点的子串有效，
                // 并且 right 向右延伸的所有子串也有效（共 n - right 个）
                ans += n - right;
                // 移动左边界，减少 left 位置的字符计数
                --count[s[left] - 'a'];
                ++left;
            }
        }
        return ans;
    }
};