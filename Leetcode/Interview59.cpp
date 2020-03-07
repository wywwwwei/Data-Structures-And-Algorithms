/**
 * 面试题59 - II. 队列的最大值  链表模拟双队列
 * link：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
 */
class MaxQueue
{
    struct Node
    {
        int val;
        Node *next;
        Node *sortNext;
        Node(int value)
        {
            val = value;
            next = NULL;
            sortNext = NULL;
        }
    };

    //Maintain the queue implemented by a linked list through head and tail
    Node *head;
    Node *tail;
    //A secondary queue that stores the maximum value through sortHead
    //Because the title does not mention that the insertion value must be different,
    //the same node pointer is used in the two queues.
    Node *sortHead;

public:
    MaxQueue()
    {
        head = NULL;
        tail = NULL;
        sortHead = NULL;
    }

    int max_value()
    {
        if (this->sortHead)
        {
            return this->sortHead->val;
        }
        return -1;
    }

    void push_back(int value)
    {
        Node *newNode = new Node(value);
        /**
         * If the value of push_back() is greater than current max_value()
         * it means that the node that current max_value() points to will not affect the maximum value if it is popped,
         * so empty the auxiliary queue and insert the node(value)
         * 
         * Otherwise, the first node that is less than or equal to value is found for replacement 
         * according to the queue pointed by sortHead
         */
        if (max_value() <= value)
        {
            this->sortHead = newNode;
        }
        else
        {
            Node *temp = this->sortHead;
            while (temp->sortNext)
            {
                if (temp->sortNext->val <= value)
                {
                    break;
                }
                temp = temp->sortNext;
            }
            temp->sortNext = newNode;
        }

        if (!this->head)
        {
            this->head = newNode;
        }
        else
        {
            this->tail->next = newNode;
        }
        this->tail = newNode;
    }

    int pop_front()
    {
        int res = -1;

        if (this->head)
        {
            if (this->sortHead == this->head)
            {
                this->sortHead = this->sortHead->sortNext;
            }

            Node *temp = this->head;
            res = this->head->val;
            this->head = this->head->next;
            if (!this->head)
            {
                this->tail = NULL;
            }
            delete (temp);
        }
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */