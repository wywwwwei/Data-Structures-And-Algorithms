/**
 * 面试题40. 最小的k个数 堆(优先队列)
 * link：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 */

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        priority_queue<int> pq;

        for (int &num : arr)
        {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};