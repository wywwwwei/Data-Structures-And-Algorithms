/**
 * 347. 前 K 个高频元素
 * link：https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        using KV = pair<int, int>;
        unordered_map<int, int> counts;
        priority_queue<KV, vector<KV>, greater<KV>> topK;
        vector<int> result(k);

        for (const auto &num : nums)
            counts[num]++;

        for (const auto &count : counts)
        {
            if (topK.size() == k)
            {
                if (count.second < topK.top().first)
                    continue;
                topK.pop();
            }
            topK.push(make_pair(count.second, count.first));
        }

        int i = 0;
        while (!topK.empty())
        {
            result[i++] = topK.top().second;
            topK.pop();
        }

        return result;
    }
};