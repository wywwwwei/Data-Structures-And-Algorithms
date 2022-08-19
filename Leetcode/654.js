/**
 * 654. 最大二叉树
 * link：https://leetcode.cn/problems/maximum-binary-tree/
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
 * @param {number[]} nums
 * @return {TreeNode}
 */
var constructMaximumBinaryTree = function (nums) {
    const n = nums.length;
    if (n === 1) {
        return new TreeNode(nums[0]);
    }
    const maxValue = Math.max(...nums);
    const index = nums.indexOf(maxValue);
    const node = new TreeNode(nums[index]);
    if (index > 0) {
        node.left = constructMaximumBinaryTree(nums.slice(0, index));
    }
    if (index + 1 < n) {
        node.right = constructMaximumBinaryTree(nums.slice(index + 1, n));
    }
    return node;
};