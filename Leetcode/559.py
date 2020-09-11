# 559. N叉树的最大深度 recursion
# link：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        elif not root.children:
            return 1
        else:
            return max([self.maxDepth(val) for val in root.children])+1
