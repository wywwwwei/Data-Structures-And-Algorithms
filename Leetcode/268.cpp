/**
 * 268. 缺失数字    Exclusive or
 * link：https://leetcode-cn.com/problems/missing-number/
 */

/**
 * a ^ a = 0
 * a ^ a ^ b ^ b ^ c = c and XOR is commutative
 */

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
            result ^= i + 1;
        }
        return result;
    }
};