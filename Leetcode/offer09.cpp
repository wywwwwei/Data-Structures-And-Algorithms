/**
 * 剑指 Offer 09. 用两个栈实现队列
 * link：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */

class CQueue
{
    stack<int> a;
    stack<int> b;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        a.push(value);
    }

    int deleteHead()
    {
        if (b.empty())
        {
            while (!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
        }

        if (b.empty())
            return -1;
            
        int result = b.top();
        b.pop();
        return result;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */