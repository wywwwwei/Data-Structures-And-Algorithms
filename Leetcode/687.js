/**
 * 687. 最长同值路径
 * link：https://leetcode.cn/problems/longest-univalue-path/
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
 * @return {number}
 */
var longestUnivaluePath = function (root) {
    let result = 0;
    const dfs = function (node) {
        if (!node) {
            return 0;
        }
        const left = dfs(node.left);
        const right = dfs(node.right);
        let newLeft = 0, newRight = 0;
        if (node.left && node.left.val === node.val) {
            newLeft = left + 1;
        }
        if (node.right && node.right.val === node.val) {
            newRight = right + 1;
        }
        result = Math.max(result, newLeft + newRight);
        return Math.max(newLeft, newRight);
    }
    dfs(root);
    return result;
};