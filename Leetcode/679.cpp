/**
 * 679. 24 点游戏   回溯
 * link：https://leetcode-cn.com/problems/24-game/
 */

class Solution
{
    static constexpr int target = 24;
    static constexpr double precision = 1e-6;

    static double Add(double x, double y);
    static double Sub(double x, double y);
    static double Mul(double x, double y);
    static double Div(double x, double y);
    static double (*operation[4])(double, double);

public:
    bool judgePoint24(vector<int> &nums)
    {
        vector<double> nums_double(nums.size());
        for (int i = 0; i < nums.size(); i++)
            nums_double[i] = static_cast<double>(nums[i]);

        return backtrack(nums_double);
    }

    bool backtrack(vector<double> &nums)
    {
        if (nums.size() == 1)
            return (abs(nums[0] - target) < precision);

        vector<double> store(nums.size() - 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                int l = 0;
                for (int k = 0; k < nums.size(); k++)
                {
                    if (k == i || k == j)
                        continue;
                    store[l++] = nums[k];
                }
                for (int k = 0; k < 4; k++)
                {
                    if (k == 3 && nums[j] < precision)
                        continue;
                    store[l] = (*operation[k])(nums[i], nums[j]);
                    if (backtrack(store))
                        return true;
                }
            }
        }
        return false;
    }
};

double Solution::Add(double x, double y) { return x + y; }
double Solution::Sub(double x, double y) { return x - y; }
double Solution::Mul(double x, double y) { return x * y; }
double Solution::Div(double x, double y) { return x / y; }
double (*Solution::operation[4])(double, double) = {Solution::Add, Solution::Sub, Solution::Mul, Solution::Div};