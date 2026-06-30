class Solution {
public:
    void climb(int n, int &ans) {
        if (n < 0) return;      // 走过头了，这条路废了
        if (n == 0) {
            ++ans;              // 刚好走完，记录一种方法
            return;             // 一定要 return，不再往下递归
        }
        climb(n - 1, ans);
        climb(n - 2, ans);
    }

    int climbStairs(int n) {
        int ans = 0;
        climb(n, ans);
        return ans;
    }
};