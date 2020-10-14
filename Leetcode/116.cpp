/**
 * 116. 填充每个节点的下一个右侧节点指针
 * link：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 */

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *cur = root;
        Node *tmp = new Node();

        Node *next_node;
        Node *last;
        while (cur)
        {
            next_node = cur;
            last = tmp;
            while (next_node != nullptr)
            {
                if (next_node->left)
                {
                    last->next = next_node->left;
                    last = next_node->left;
                }
                if (next_node->right)
                {
                    last->next = next_node->right;
                    last = next_node->right;
                }
                next_node = next_node->next;
            }
            cur = tmp->next;
            tmp->next = nullptr;
        }

        return root;
    }
};