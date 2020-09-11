# 513. 找树左下角的值 BFS from right to left
# link：https://leetcode-cn.com/problems/find-bottom-left-tree-value/

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        queue = [root]

        while queue:
            node: TreeNode = queue.pop(0)
            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)

        return node.val
