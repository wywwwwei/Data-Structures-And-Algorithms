/**
 * 295. 数据流的中位数  max heap + min heap
 * link：https://leetcode-cn.com/problems/find-median-from-data-stream/
 */

class MedianFinder
{
    priority_queue<int> front;
    priority_queue<int, vector<int>, greater<int>> back;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        front.push(num);

        back.push(front.top());
        front.pop();

        if (front.size() < back.size())
        {
            front.push(back.top());
            back.pop();
        }
    }

    double findMedian()
    {
        if (front.size() > back.size())
            return static_cast<double>(front.top());
        return 0.5 * (front.top() + back.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */