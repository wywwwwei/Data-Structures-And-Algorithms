/**
 * 669. 修剪二叉搜索树
 * link：https://leetcode.cn/problems/trim-a-binary-search-tree/
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
 * @param {number} low
 * @param {number} high
 * @return {TreeNode}
 */
var trimBST = function (root, low, high) {
    const trim = function (node) {
        if (!node) {
            return null;
        }
        if (node.val < low) {
            return trim(node.right);
        }
        if (node.val > high) {
            return trim(node.left);
        }
        node.left = trim(node.left);
        node.right = trim(node.right);
        return node;
    };
    return trim(root);
};