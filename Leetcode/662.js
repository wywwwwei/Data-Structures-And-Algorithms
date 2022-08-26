/**
 * 662. 二叉树最大宽度
 * link：https://leetcode.cn/problems/maximum-width-of-binary-tree/
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
var widthOfBinaryTree = function (root) {
    if (!root) {
        return 0;
    }
    const queue = [[root, 0]];
    let result = 1;
    while (queue.length > 0) {
        const n = queue.length;
        let fromWidth = -1;
        let toWidth = -1;
        for (let i = 0; i < n; i++) {
            const nodeInfo = queue.shift();
            const node = nodeInfo[0];
            const index = nodeInfo[1];
            if (fromWidth < 0) {
                fromWidth = index;
            }
            toWidth = index;
            if (node.left) {
                queue.push([node.left, 2 * index - fromWidth]);
            }
            if (node.right) {
                queue.push([node.right, 2 * index + 1 - fromWidth]);
            }
        }
        result = Math.max(result, toWidth - fromWidth + 1);
    }
    return result;
};