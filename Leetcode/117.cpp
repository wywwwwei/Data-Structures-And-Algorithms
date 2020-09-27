/**
 * 117. 填充每个节点的下一个右侧节点指针 II     Level order traversal (linked list optimized)
 * link：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
 */

class Solution
{
    void setLastNext(Node *&last, Node *&cur, Node *&next_leftmost)
    {
        if (last)
            last->next = cur;
        if (next_leftmost == nullptr)
            next_leftmost = cur;
        last = cur;
    }

public:
    Node *connect(Node *root)
    {
        Node *cur = root;
        Node *next_leftmost = nullptr;

        while (cur)
        {
            Node *last = nullptr;
            for (Node *p = cur; p != nullptr; p = p->next)
            {
                if (p->left)
                {
                    setLastNext(last, p->left, next_leftmost);
                }
                if (p->right)
                {
                    setLastNext(last, p->right, next_leftmost);
                }
            }
            cur = next_leftmost;
            next_leftmost = nullptr;
        }

        return root;
    }
};