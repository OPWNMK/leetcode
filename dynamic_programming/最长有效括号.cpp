#include "commen.h"


class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<char> left;
        vector<char> right;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left.push_back(s[i]);
            }
            else
            {
                right.push_back(s[i]);
            }
        }
        int ans = 0;
        while(!left.empty() && !right.empty())
        {
            left.pop_back();
            right.pop_back();
            ans += 2;
        }
        return ans;
    }
};
