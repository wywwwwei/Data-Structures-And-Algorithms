# 226. 翻转二叉树 BFS
# link: https://leetcode-cn.com/problems/invert-binary-tree/


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

        nodes = collections.deque([root])
        while nodes:
            node: TreeNode = nodes.popleft()
            node.left, node.right = node.right, node.left
            if node.left:
                nodes.append(node.left)
            if node.right:
                nodes.append(node.right)

        return root
