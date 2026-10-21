#include "commen.h"
class Solution
{
public:
    int minOperations(string s)
    {
        char mx = 'a';
        char mn = 'z';
        int len = s.size();
        bool is_sorted = true;
        for (int i = 0; i < len - 1; ++i)
        {
            if (s[i] > s[i + 1])
            {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted)
            return 0;
        if (len == 2)
            return -1;
        for (int i = 0; i < len; ++i)
        {
            mx = max(mx, s[i]);
            mn = min(mn, s[i]);
        }
        if (s[0] == mn || s[len - 1] == mx)
            return 1;
        for (int i = 1; i < len - 1; ++i)
        {
            if (mn == s[i] || mx == s[len - i - 1])
            {
                return 2;
            }
        }
        return 3;
    }
};