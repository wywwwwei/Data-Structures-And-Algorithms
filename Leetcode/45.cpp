/**
 * 45. 跳跃游戏 II
 * link：https://leetcode-cn.com/problems/jump-game-ii/
 */

/*
// Before simplify
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int result = 0;

        int i = 0;
        int max_i = n - 1;
        while (i < max_i)
        {
            int end = i + nums[i];
            if (n - 1 <= end)
                return result + 1;

            int max_dis = 0;
            for (int j = i + 1; j <= end; j++)
                max_dis = max(max_dis, j + nums[j]);

            nums[end] = max_dis - end;
            result++;
            i = end;
        }
        return result;
    }
};
*/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int result = 0;

        int i = 0;
        int cur_end = 0;
        int max_i = n - 1;
        int max_dis = 0;
        while (i < max_i)
        {
            max_dis = max(max_dis, i + nums[i]);
            if (i == cur_end)
            {
                cur_end = max_dis;
                result++;
            }
            i++;
        }
        return result;
    }
};