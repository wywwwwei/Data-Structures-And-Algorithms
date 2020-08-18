/**
 * 108. 将有序数组转换为二叉搜索树
 * link：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return arrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *arrayToBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        else if(left == right)
            return new TreeNode(nums[left]);

        int mid = left + (right - left) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = arrayToBST(nums, left, mid - 1);
        cur->right = arrayToBST(nums, mid + 1, right);

        return cur;
    }
};