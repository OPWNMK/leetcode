#include "commen.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int left = 0, right = 0;
        int maxLen = 0;
        while (right < s.size()) {
            char c = s[right];
            count[c]++;
            // 当出现重复，移动左边界直到重复消失
            while (count[c] > 1) {
                count[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};