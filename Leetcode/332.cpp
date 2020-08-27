/**
 * 332. 重新安排行程
 * link：https://leetcode-cn.com/problems/reconstruct-itinerary/
 */

/**
 * Hierholzer's Algorithm
 * Related problems:
 * 753. Cracking the Safe
 * https://leetcode-cn.com/problems/cracking-the-safe/
 */

class Solution
{
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> path;
    vector<string> result;

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (const auto &ticket : tickets)
        {
            path[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(const string &cur)
    {
        if (path.find(cur) != path.end())
        {
            auto &vec = path[cur];
            while (vec.size() > 0)
            {
                string next = vec.top();
                vec.pop();
                dfs(next);
            }
        }
        result.push_back(cur);
    }
};
