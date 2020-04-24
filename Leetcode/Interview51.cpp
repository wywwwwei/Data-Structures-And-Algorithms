/**
 * 面试题51. 数组中的逆序对
 * link：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 */

class FenwickTree
{
private:
    vector<int> tree;
    int n;

    //return 2 ^ the position of the last bit
    int lowbit(int x)
    {
        return x & (-x);
    }

public:
    FenwickTree(int _n) : n(_n), tree(_n + 1) {}

    int query(int idx)
    {
        int sum = 0;
        while (idx)
        {
            sum += tree[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }

    void update(int idx)
    {
        while (idx <= n)
        {
            tree[idx]++;
            idx += lowbit(idx);
        }
    }
};

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        //Discretization
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        for (auto &num : nums)
        {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }

        int result = 0;
        FenwickTree ft(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result += ft.query(nums[i] - 1);
            ft.update(nums[i]);
        }
        return result;
    }
};