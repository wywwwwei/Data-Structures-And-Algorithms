/**
 * 623. 在二叉树中增加一行
 * link：https://leetcode.cn/problems/add-one-row-to-tree/
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
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function (root, val, depth) {
    if (!root) {
        return root;
    }
    if (depth === 1) {
        return new TreeNode(val, root, null);
    }
    const queue = [];
    queue.push(root);
    while (depth - 1 > 1) {
        const n = queue.length;
        for (let i = 0; i < n; i++) {
            const node = queue.shift();
            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
            }
        }
        depth--;
    }
    for (const node of queue) {
        node.left = new TreeNode(val, node.left, null);
        node.right = new TreeNode(val, null, node.right);
    }
    return root;
};
