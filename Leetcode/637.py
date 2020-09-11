# 637. 二叉树的层平均值 level order traversal
# link：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []

        average = list()
        queue = collections.deque([root])

        while queue:
            total: float = 0
            size = len(queue)

            for _ in range(size):
                node = queue.popleft()
                total += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            average.append(total/size)

        return average
