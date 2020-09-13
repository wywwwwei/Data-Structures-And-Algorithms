# 94. 二叉树的中序遍历  Morris Traversal
# link：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result = []

        while root:
            if root.left:
                predecessor: TreeNode = root.left
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right

                if not predecessor.right:
                    predecessor.right = root
                    root = root.left
                else:
                    result.append(root.val)
                    predecessor.right = None
                    root = root.right
            else:
                result.append(root.val)
                root = root.right

        return result
