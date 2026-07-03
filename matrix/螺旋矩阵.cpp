#include "commen.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        
        while (left <= right && top <= bottom) {
            // 1. 从左到右（上边）
            for (int j = left; j <= right; ++j)
                ans.push_back(matrix[top][j]);
            ++top;
            
            // 2. 从上到下（右边）
            for (int i = top; i <= bottom; ++i)
                ans.push_back(matrix[i][right]);
            --right;
            
            // 3. 从右到左（下边） 
            if (top <= bottom) {
                for (int j = right; j >= left; --j)
                    ans.push_back(matrix[bottom][j]);
                --bottom;
            }
            
            // 4. 从下到上（左边） 
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    ans.push_back(matrix[i][left]);
                ++left;
            }
        }
        return ans;
    }
};