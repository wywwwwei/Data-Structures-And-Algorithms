# 501. 二叉搜索树中的众数
# link：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        result = []
        last: int = 0
        cur_count: int = 0
        max_count: int = 0

        def update(cur: int):
            nonlocal cur_count, last, max_count, result
            if last == cur:
                cur_count += 1
            else:
                if cur_count == max_count and max_count > 0:
                    result.append(last)
                elif cur_count > max_count:
                    result.clear()
                    result.append(last)
                    max_count = cur_count
                last = cur
                cur_count = 1

        while root:
            if not root.left:
                update(root.val)
                root = root.right
            else:
                predecessor: TreeNode = root.left
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right
                if not predecessor.right:
                    predecessor.right = root
                    root = root.left
                else:
                    predecessor.right = None
                    update(root.val)
                    root = root.right
        update(last ^ 1)
        return result
