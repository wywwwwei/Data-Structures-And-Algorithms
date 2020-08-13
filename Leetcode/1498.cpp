/**
 * 1498. 满足条件的子序列数目
 * link：https://leetcode-cn.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
 */

/**
 * For a given Vmin and Vmax, the number of non-empty subsequences depends on how many numbers between them
 * e.g.
 * [Vmin, V1, V2, V3,..., Vmax], the number of non-empty subsequences is 2^(index(Vmax) - index(Vmin))
 * which means that only Vmin is required for the subsequence that satisfies the condition.
 * 
 * However, index(Vmax) - index(Vmin) < 10 ^ 5, so there is an overflow situation.
 * According to 
 * (a * b) % c = ((a % c) * (b % c)) % c,
 * We can generate an array that stores 2 ^ index's remainder
 */

class Solution
{
    static constexpr int Mod = int(1E9) + 7;
    vector<int> table;

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        buildTable(nums.size());

        int result = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                result = (result + table[right - left]) % Mod;
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
    }

    void buildTable(int length)
    {
        table.resize(length, 0);
        table[0] = 1;
        for (int i = 1; i < table.size(); i++)
        {
            table[i] = (table[i - 1] * 2) % Mod;
        }
    }
};