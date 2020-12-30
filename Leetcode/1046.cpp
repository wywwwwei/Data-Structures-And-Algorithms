/**
 * 1046. 最后一块石头的重量
 * link：https://leetcode-cn.com/problems/last-stone-weight/
 */

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (const int stone : stones)
            pq.push(stone);

        while (pq.size() > 1)
        {
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();
            if (tmp1 > tmp2)
                pq.push(tmp1 - tmp2);
        }

        return pq.empty() ? 0 : pq.top();
    }
};