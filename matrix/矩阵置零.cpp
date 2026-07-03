#include "commen.h"

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // unordered_set<int> row_index;  // 行
        // unordered_set<int> line_index; // 列
        // for (int i = 0; i < matrix.size(); ++i)
        // {
        //     for (int j = 0; j < matrix[0].size(); ++j)
        //     {
        //         if (matrix[i][j] == 0)
        //         {
        //             row_index.insert(i);
        //             line_index.insert(j);
        //         }
        //     }
        // }
        // for(int num:row_index)
        // {
        //     for(int j = 0;j < matrix[0].size();++j)
        //     {
        //         matrix[num][j] = 0;
        //     }
        // }
        // for(int num:line_index)
        // {
        //     for(int j = 0;j < matrix.size();++j)
        //     {
        //         matrix[j][num] = 0;
        //     }
        // }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};