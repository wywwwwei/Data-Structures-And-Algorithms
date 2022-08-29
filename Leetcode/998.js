/**
 * 998. 最大二叉树 II
 * link：https://leetcode.cn/problems/maximum-binary-tree-ii/
 */

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoMaxTree = function (root, val) {
    if (!root || val > root.val) {
        return new TreeNode(val, root, null);
    } else {
        root.right = insertIntoMaxTree(root.right, val);
    }
    return root;
};