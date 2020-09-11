# 429. N叉树的层序遍历
# link：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []

        queue = collections.deque([root])
        result = []
        while queue:
            cur = []
            for i in range(len(queue)):
                tmp: Node = queue.popleft()
                cur.append(tmp.val)
                queue.extend(tmp.children)
            result.append(cur)

        return result
