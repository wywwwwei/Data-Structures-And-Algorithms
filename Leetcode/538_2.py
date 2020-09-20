# 538. 把二叉搜索树转换为累加树    Morris
# link：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        def getSuccessor(cur: TreeNode) -> TreeNode:
            find: TreeNode = cur.right
            while find.left and find.left != cur:
                find = find.left
            return find

        cur: TreeNode = root
        sum: int = 0

        while cur:
            if cur.right:
                successor: TreeNode = getSuccessor(cur)
                if successor.left:
                    successor.left = None
                    sum += cur.val
                    cur.val = sum
                    cur = cur.left
                else:
                    successor.left = cur
                    cur = cur.right
            else:
                sum += cur.val
                cur.val = sum
                cur = cur.left

        return root
