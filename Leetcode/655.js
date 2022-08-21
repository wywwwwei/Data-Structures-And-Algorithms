/**
 * 655. 输出二叉树
 * link：https://leetcode.cn/problems/print-binary-tree/
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
 * @return {string[][]}
 */
var printTree = function (root) {
    const treeDepth = (root) => {
        if (!root) {
            return 0;
        }
        return Math.max(treeDepth(root.left), treeDepth(root.right)) + 1;
    };
    const depth = treeDepth(root);
    const result = new Array(depth).fill(null).map(() => new Array(2 ** depth - 1).fill(""));
    const fillMatrix = (matrix, root, x, y, depth) => {
        matrix[x][y] = root.val.toString();
        const leaveOffset = 2 ** (depth - 1 - x - 1);
        if (root.left) {
            fillMatrix(matrix, root.left, x + 1, y - leaveOffset, depth);
        }
        if (root.right) {
            fillMatrix(matrix, root.right, x + 1, y + leaveOffset, depth);
        }
    }
    fillMatrix(result, root, 0, Math.floor((2 ** depth - 1) / 2), depth);
    return result;
};