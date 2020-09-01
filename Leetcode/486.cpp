/**
 * 486. 预测赢家
 * link：https://leetcode-cn.com/problems/predict-the-winner/
 */

/**
 * A more detailed explanation is available at
 * 877. Stone Game  https://leetcode-cn.com/problems/stone-game/
 * 
 * 1. An even number of scores
 * As long as the first hand selects all scores with odd or even indexes, the first hand wins
 * s(odd) >= s(even) -> choose all scores with odd indexes
 * s(odd) <  s(even) -> choose all scores with even indexes
 * 
 * 2. dynamic programming
 * use dp to store the difference between the scores of two players from the bottom up
 */

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        if (n % 2 == 0)
            return true;

        vector<int> dp(nums);

        for (int j = 1; j < n; j++)
            for (int i = 0; i < n - j; i++)
                dp[i] = max(nums[i] - dp[i + 1], nums[i + j] - dp[i]);

        return dp[0] >= 0;
    }
};