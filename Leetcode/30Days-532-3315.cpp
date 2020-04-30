/**
 * Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree  DFS 
 * link：https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        return dfs(root, arr, 0);
    }

    bool dfs(TreeNode *root, vector<int> &arr, int step)
    {
        if (step >= arr.size() || root == nullptr || arr[step] != root->val)
            return false;

        return dfs(root->left, arr, step + 1) || dfs(root->right, arr, step + 1) || (step == arr.size() - 1 && root->left == nullptr && root->right == nullptr);
    }
};