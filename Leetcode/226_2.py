# 226. 翻转二叉树 递归DFS
# link: https://leetcode-cn.com/problems/invert-binary-tree/

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root