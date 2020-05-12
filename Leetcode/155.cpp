/**
 * 155. 最小栈  O(1)getMin() -> 辅助栈
 * link：https://leetcode-cn.com/problems/min-stack/
 */

class MinStack {
    stack<int> minVal;
    stack<int> record;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        record.push(x);
        if(minVal.empty() || minVal.top() >= x)minVal.push(x);
    }
    
    void pop() {
        if(record.top() == minVal.top()){
            minVal.pop();
        }
        record.pop();
    }
    
    int top() {
        return record.top();
    }
    
    int getMin() {
        return minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */