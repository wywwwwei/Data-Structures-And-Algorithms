# 968. 监控二叉树  Recursion
# link：https://leetcode-cn.com/problems/binary-tree-cameras/

from enum import Enum

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        result: int = 0

        class State(Enum):
            kNull = 1
            kCamera = 2
            kWatched = 3
            kUnwatched = 4

        def dfs(cur: TreeNode) -> State:
            if not cur:
                return State.kNull

            left: State = dfs(cur.left)
            right: State = dfs(cur.right)

            if left == State.kUnwatched or right == State.kUnwatched:
                nonlocal result
                result += 1
                return State.kCamera

            if left == State.kCamera or right == State.kCamera:
                return State.kWatched
            
            return State.kUnwatched

        if dfs(root) == State.kUnwatched:
            result += 1
        return result
