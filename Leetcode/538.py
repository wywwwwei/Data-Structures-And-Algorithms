# 538. 把二叉搜索树转换为累加树    dfs
# link：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

class Solution:
    def __init__(self) -> None:
        self.sum = 0

    def convertBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

        self.convertBST(root.right)
        self.sum += root.val
        root.val = self.sum
        self.convertBST(root.left)

        return root
