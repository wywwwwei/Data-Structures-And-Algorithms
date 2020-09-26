# 113. 路径总和 II  dfs
# link：https://leetcode-cn.com/problems/path-sum-ii/


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return []
        path = []
        result = []
        curSum: int = 0

        def dfs(cur: TreeNode) -> None:
            nonlocal curSum
            curSum += cur.val
            path.append(cur.val)

            if cur.left:
                dfs(cur.left)
            if cur.right:
                dfs(cur.right)
            if not cur.left and not cur.right:
                if sum == curSum:
                    result.append(path.copy())

            curSum -= cur.val
            path.pop()

        dfs(root)
        return result
