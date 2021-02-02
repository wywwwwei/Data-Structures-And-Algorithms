/**
 * 480. 滑动窗口中位数  max heap + min heap + delayed delete
 * link：https://leetcode-cn.com/problems/sliding-window-median/
 */

class MedianFinder
{
    priority_queue<int> front;
    int frontSize = 0;
    priority_queue<int, vector<int>, greater<int>> back;
    int backSize = 0;
    unordered_map<int, int> delayDel;

    int window;

    template <class T>
    void prune(T &heap)
    {
        while (!heap.empty())
        {
            int cur = heap.top();
            if (delayDel[cur] > 0)
            {
                --delayDel[cur];
                heap.pop();
            }
            else
                break;
        }
    }

    void balance()
    {
        if (frontSize > backSize + 1)
        {
            back.push(front.top());
            front.pop();
            ++backSize;
            --frontSize;
            prune(front);
        }
        else if (backSize > frontSize)
        {
            front.push(back.top());
            back.pop();
            ++frontSize;
            --backSize;
            prune(back);
        }
    }

public:
    MedianFinder(int window) : window(window) {}
    void insert(int val)
    {
        if (front.empty() || val <= front.top())
        {
            front.push(val);
            ++frontSize;
        }
        else
        {
            back.push(val);
            ++backSize;
        }
        balance();
    }
    void remove(int val)
    {
        ++delayDel[val];
        if (val <= front.top())
        {
            --frontSize;
            if (val == front.top())
                prune(front);
        }
        else
        {
            --backSize;
            if (val == back.top())
                prune(back);
        }
        balance();
    }
    double getMedian()
    {
        return frontSize > backSize ? 1.0 * front.top() : 0.5 * (1.0 * front.top() + back.top());
    }
};
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();

        MedianFinder finder(k);
        vector<double> result(n - k + 1);

        for (int i = 0; i < k; i++)
            finder.insert(nums[i]);
        int curWindow = 0;
        result[curWindow++] = finder.getMedian();

        for (int i = k; i < n; i++)
        {
            finder.remove(nums[i - k]);
            finder.insert(nums[i]);
            result[curWindow++] = finder.getMedian();
        }

        return result;
    }
};