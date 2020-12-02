/**
 * 321. 拼接最大数
 * link：https://leetcode-cn.com/problems/create-maximum-number/
 */

class Solution
{
    vector<int> subStack(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> stack(k, 0);
        int top = 0;
        int canDrop = n - k;
        for (int i = 0; i < n; i++)
        {
            while (top > 0 && stack[top - 1] < nums[i] && canDrop > 0)
            {
                top--;
                canDrop--;
            }
            if (top < k)
                stack[top++] = nums[i];
            else
                canDrop--;
        }
        return stack;
    }

    void merge(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m == 0)
            return nums1.swap(nums2);
        if (n == 0)
            return;

        int l = 0, r = 0;
        vector<int> tmp(m + n, 0);
        for (int i = 0; i < m + n; i++)
        {
            if (cmp(nums1, l, nums2, r))
                tmp[i] = nums2[r++];
            else
                tmp[i] = nums1[l++];
        }

        nums1.resize(m + n);
        copy(tmp.begin(), tmp.end(), nums1.begin());
    }

    bool cmp(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2)
    {
        int n = nums1.size();
        int m = nums2.size();
        while (idx1 < n && idx2 < m)
        {
            if (nums1[idx1] != nums2[idx2])
                return nums1[idx1] < nums2[idx2];
            idx1++;
            idx2++;
        }
        return (n - idx1) < (m - idx2);
    }

public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        int start = max(0, k - n), end = min(m, k);

        vector<int> result(k, 0);
        for (int i = start; i <= end; i++)
        {
            vector<int> left(subStack(nums1, i));
            vector<int> right(subStack(nums2, k - i));

            merge(left, right);

            if (cmp(result, 0, left, 0))
                result.swap(left);
        }
        return result;
    }
};