# 106. 从中序与后序遍历序列构造二叉树  迭代法
# link: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None

        root: TreeNode = TreeNode(postorder[-1])
        root_nodes = [root]
        postorder.pop()

        while postorder:
            cur_root: TreeNode = None

            while root_nodes and inorder[-1] == root_nodes[-1].val:
                cur_root = root_nodes[-1]
                root_nodes.pop()
                inorder.pop()

            cur: TreeNode = TreeNode(postorder[-1])
            postorder.pop()

            if cur_root:
                cur_root.left = cur
            else:
                root_nodes[-1].right = cur

            root_nodes.append(cur)

        return root
