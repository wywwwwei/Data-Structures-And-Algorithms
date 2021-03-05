/**
 * 232. 用栈实现队列
 * link：https://leetcode-cn.com/problems/implement-queue-using-stacks/
 */

class MyQueue
{
    stack<int> first;
    stack<int> second;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        first.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int result = peek();
        second.pop();

        return result;
    }

    /** Get the front element. */
    int peek()
    {
        if (second.empty())
        {
            while (!first.empty())
            {
                second.push(first.top());
                first.pop();
            }
        }

        return second.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return first.empty() && second.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */