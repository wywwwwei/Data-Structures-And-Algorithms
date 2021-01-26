/**
 * 1128. 等价多米诺骨牌对的数量
 * link：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
 */

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        // 1 <= dominoes[i][j] <= 9
        // 11 <= dominoes[i][0] * 10 + dominoes[i][1] <= 99
        vector<int> count(100, 0);

        int result = 0;
        for (const auto &dominoe : dominoes)
        {
            int val = dominoe[0] < dominoe[1] ? dominoe[0] * 10 + dominoe[1] : dominoe[1] * 10 + dominoe[0];
            result += count[val];
            ++count[val];
        }
        return result;
    }
};