/**
 * 659. 分割数组为连续子序列
 * link：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/
 */

/**
 * This problem is to find how to keep all subsequences (ending + length)
 */
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> sequence;
        unordered_map<int, int> count;
        for (const auto &num : nums)
            count[num]++;

        for (const auto &num : nums)
        {
            if (count[num] <= 0)
                continue;
            if (sequence.find(num - 1) != sequence.end() && sequence[num - 1] > 0)
            {
                sequence[num - 1]--;
                sequence[num]++;
            }
            else
            {
                if (count[num + 1]-- <= 0 || count[num + 2]-- <= 0)
                    return false;
                sequence[num + 2]++;
            }
            count[num]--;
        }

        return true;
    }
};