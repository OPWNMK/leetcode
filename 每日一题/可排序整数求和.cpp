#include "commen.h"

class Solution
{
public:
    vector<int> &get_candi_k(int n)
    {
        vector<int> ret;
        for(int i = 1;i <= n;++i)
        {
            if(n % i == 0)
            {
                ret.push_back(i);
                if(n / i != i)
                {
                    ret.push_back(n / i);
                }
            }
        }
        return ret;
    }
    
    int sortableIntegers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> candi_k;
        int ans = 0;
    
        return ans;
    }
};
