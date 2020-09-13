# 94. 二叉树的中序遍历  Recursion
# link：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result = []

        def dfs(cur: TreeNode):
            if not cur:
                return

            dfs(cur.left)
            result.append(cur.val)
            dfs(cur.right)

        dfs(root)
        return result
