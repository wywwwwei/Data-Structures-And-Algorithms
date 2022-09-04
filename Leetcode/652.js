/**
 * 652. 寻找重复的子树
 * link：https://leetcode.cn/problems/find-duplicate-subtrees/
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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function (root) {
    const nodeSet = new Set();
    const resultSet = new Set();
    const result = new Array();
    const dfs = function (node) {
        if (!node) {
            return "";
        }
        const left = dfs(node.left);
        const right = dfs(node.right);
        const current = node.val.toString() + "(" + left + ")(" + right + ")";
        if (nodeSet.has(current) && !resultSet.has(current)) {
            result.push(node);
            resultSet.add(current);
        }
        nodeSet.add(current);
        return current;
    }
    dfs(root);
    return result;
};