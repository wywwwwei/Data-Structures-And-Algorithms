/**
 * 703. 数据流中的第 K 大元素
 * link：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
 */

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int num : nums)
            add(num);
    }

    int add(int val)
    {
        if (minHeap.size() < k)
        {
            minHeap.push(val);
        }
        else if (val > minHeap.top())
        {
            minHeap.push(val);
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */