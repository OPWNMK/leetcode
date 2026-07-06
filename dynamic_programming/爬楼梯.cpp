class Solution
{
public:
    void climb(int n, int &ans)
    {
        if (n < 0)
            return; // 走过头了，这条路废了
        if (n == 0)
        {
            ++ans; // 刚好走完，记录一种方法
            return;
        }
        climb(n - 1, ans);
        climb(n - 2, ans);
    }

    /**
     * 递归方法，时间复杂度O(n^2)超时
     */
    int climbStairs(int n)
    {
        int ans = 0;
        climb(n, ans);
        return ans;
    }

    /**
     * 楼梯阶数小于2时，直接返回
     * 本题可以转换为求解波那契数列
     */
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int a = 1, b = 2; // 分别代表 dp[1], dp[2]
        for (int i = 3; i <= n; ++i)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};