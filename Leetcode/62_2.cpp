/**
 * 62. 不同路径
 * link：https://leetcode-cn.com/problems/unique-paths/
 */

/**
 * C(m-1)(m+n-2) 
 * = (m+n-2)*(m+n-3)*...*n / (m-1)! 
 * = (m+n-2)! / (m-1)! / (n-1)!
 */

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return round(tgamma(m + n - 1) / tgamma(m) / tgamma(n));
    }
};