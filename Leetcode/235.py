# 235. 二叉搜索树的最近公共祖先    Recursion / Iteration
# link：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

# Recursion
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None

        if root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root

# Iteration
# class Solution:
#     def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
#         cur : TreeNode = root
#         while cur:
#             if cur.val > p.val and cur.val > q.val:
#                 cur = cur.left
#             elif cur.val < p.val and cur.val < q.val:
#                 cur = cur.right
#             else:
#                 return cur
#         return cur
