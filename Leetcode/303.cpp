/**
 * 2. 两数相加 一般的进位加减
 * link：https://leetcode-cn.com/problems/range-sum-query-immutable/submissions/
 */

class NumArray
{
private:
    vector<int>result;

public:
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        result.resize(n+1,0);
        for (int i = 0; i < n; i++)
        {
            result[i + 1] = result[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return result[j + 1] - result[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */