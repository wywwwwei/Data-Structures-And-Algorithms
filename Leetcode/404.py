# 404. 左叶子之和
# link：https://leetcode-cn.com/problems/sum-of-left-leaves/


class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        def isLeaf(cur: TreeNode) -> bool:
            return not cur.left and not cur.right

        def dfs(cur: TreeNode) -> int:
            res = 0
            if cur.left:
                if isLeaf(cur.left):
                    res = cur.left.val
                else:
                    res += dfs(cur.left)

            if cur.right:
                res += dfs(cur.right)
            return res

        return dfs(root) if root else 0
