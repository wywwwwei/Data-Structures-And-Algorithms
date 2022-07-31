/**
 * 1161. 最大层内元素和
 * link：https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/
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
var maxLevelSum = function (root) {
    if (!root) {
        return -1;
    }
    let result = 1, maxSum = root.val;
    const queue = new Array();
    queue.push(root);
    for (let level = 1; queue.length > 0; level++) {
        const n = queue.length;
        let sum = 0;
        for (let i = 0; i < n; i++) {
            const node = queue.shift();
            sum += node.val;
            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            result = level;
        }
    }
    return result;
};