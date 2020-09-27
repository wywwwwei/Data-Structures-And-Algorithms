# 117. 填充每个节点的下一个右侧节点指针 II     Level order traversal (linked list optimized)
# link：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        cur: Node = root
        next_left = Node(0)

        while cur:
            p: Node = cur
            prev: Node = next_left

            while p:
                if p.left:
                    prev.next = p.left
                    prev = prev.next
                if p.right:
                    prev.next = p.right
                    prev = prev.next
                p = p.next

            cur = next_left.next
            next_left.next = None

        return root
