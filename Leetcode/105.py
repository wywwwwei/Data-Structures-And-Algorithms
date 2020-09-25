# 105. 从前序与中序遍历序列构造二叉树  迭代法
# link: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None

        pre_idx: int = 0
        in_indx: int = 0
        root: TreeNode = TreeNode(preorder[pre_idx])
        root_nodes = [root]
        pre_idx += 1

        while pre_idx < len(preorder):
            cur_root: TreeNode = None

            while root_nodes and inorder[in_indx] == root_nodes[-1].val:
                cur_root = root_nodes[-1]
                root_nodes.pop()
                in_indx += 1

            cur: TreeNode = TreeNode(preorder[pre_idx])
            pre_idx += 1

            if cur_root:
                cur_root.right = cur
            else:
                root_nodes[-1].left = cur

            root_nodes.append(cur)

        return root
