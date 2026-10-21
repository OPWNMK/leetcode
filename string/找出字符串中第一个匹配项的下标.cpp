#include "commen.h"

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int ans = -1;
        int h_len = haystack.size();
        int n_len = needle.size();
        int patch_index = 0;

        while (patch_index + n_len < h_len)
        {
            int ni = 0;
            for (int i = patch_index; i < patch_index + n_len; ++i)
            {
                if(haystack[i] == needle[ni])
                {
                    
                }
            }
        }
    }
};
