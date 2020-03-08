/**
 * 88. 合并两个有序数组 双指针从尾部开始比较
 * link：https://leetcode-cn.com/problems/merge-sorted-array/
 */

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1;
        int fillPos = m + n - 1;
        while (j >= 0)
        {
            //Consider whether nums1 has completed the merge
            if (i < 0 || nums1[i] <= nums2[j])
            {
                nums1[fillPos--] = nums2[j--];
            }
            else
            {
                nums1[fillPos--] = nums1[i--];
            }
        }
    }
};