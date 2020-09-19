/**
 * 307. 区域和检索 - 数组可修改 线段树(数组实现)
 * link：https://leetcode-cn.com/problems/range-sum-query-mutable/
 */

class NumArray
{
    vector<int> store;
    int n;

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        store.resize(2 * n);

        for (int i = 0; i < n; i++)
            store[i + n] = nums[i];
        for (int i = n - 1; i > 0; i--)
            store[i] = store[2 * i] + store[2 * i + 1];
    }

    void update(int i, int val)
    {
        int pos = i + n;
        int diff = val - store[pos];

        store[pos] = val;

        while (pos > 0)
        {
            store[pos / 2] += diff;
            pos /= 2;
        }
    }

    int sumRange(int i, int j)
    {
        i += n;
        j += n;
        int sum = 0;
        while (i <= j)
        {
            if (i % 2 == 1)
            {
                sum += store[i];
                i++;
            }
            if (j % 2 == 0)
            {
                sum += store[j];
                j--;
            }
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */