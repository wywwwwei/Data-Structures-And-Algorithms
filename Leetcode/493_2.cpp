/**
 * 493. 翻转对  BIT
 * link：https://leetcode-cn.com/problems/reverse-pairs/
 */

class Solution
{
    vector<int> tree;
    int m = 0;

    void update(int x, int val)
    {
        while (x <= m)
        {
            tree[x] += val;
            x += (x & -x);
        }
    }

    int query(int x) const
    {
        int result = 0;
        while (x > 0)
        {
            result += tree[x];
            x -= (x & -x);
        }
        return result;
    }

    using ll = long long;

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        set<ll> allNumbers;
        for (const int &x : nums)
        {
            allNumbers.insert(x);
            allNumbers.insert(2LL * x);
        }
        unordered_map<ll, int> descret;
        for (const ll &x : allNumbers)
        {
            descret[x] = ++m;
        }

        // vector<ll> descret(nums.size());
        // for (int i = 0; i < n; i++)
        //     descret[i] = nums[i];

        // vector<ll> db(descret);
        // for (auto &num : db)
        //     num *= 2;
        // descret.insert(descret.end(), db.begin(), db.end());

        // sort(descret.begin(), descret.end());
        // m = unique(descret.begin(), descret.end()) - descret.begin();
        // for (int i = 0; i < n; i++)
        // {
        //     nums[i] = lower_bound(descret.begin(), descret.begin() + m, nums[i]) - descret.begin() + 1;
        //     db[i] = lower_bound(descret.begin(), descret.begin() + m, db[i]) - descret.begin() + 1;
        // }

        tree.resize(m + 1, 0);
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            result += query(m) - query(descret[2LL * nums[i]]);
            update(descret[nums[i]], 1);
        }
        return result;
    }
};