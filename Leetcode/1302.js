/**
 * 1302. 层数最深叶子节点的和
 * link：https://leetcode.cn/problems/deepest-leaves-sum/
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
var deepestLeavesSum = function (root) {
    if (!root) {
        return 0;
    }

    const queue = [root];
    let result;
    while (queue.length > 0) {
        const n = queue.length;
        result = 0;
        for (let i = 0; i < n; i++) {
            const node = queue.shift();
            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
            }
            result += node.val;
        }
    }

    return result;
};