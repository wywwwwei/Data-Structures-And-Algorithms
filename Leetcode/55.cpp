/**
 * 55. 跳跃游戏
 * link：https://leetcode-cn.com/problems/jump-game/
 */

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int count = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            count--;
            count = max(count, nums[i]);
            if (count <= 0)
                return false;
        }

        return true;
    }
};