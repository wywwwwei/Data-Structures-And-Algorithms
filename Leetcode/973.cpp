/**
 * 973. 最接近原点的 K 个点     Max Heap
 * link：https://leetcode-cn.com/problems/k-closest-points-to-origin/
 */

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        auto cmp = [&points](const int &a, const int &b) -> bool {
            return sqrt(points[a][0] * points[a][0] + points[a][1] * points[a][1]) < sqrt(points[b][0] * points[b][0] + points[b][1] * points[b][1]);
        };
        priority_queue<int, vector<int>, function<bool(const int &, const int &)>> q{cmp};
        for (int i = 0; i < points.size(); i++)
        {
            if (i >= K)
            {
                if (cmp(i, q.top()))
                {
                    q.pop();
                    q.push(i);
                }
            }
            else
            {
                q.push(i);
            }
        }

        vector<vector<int>> result;
        while (!q.empty())
        {
            result.push_back(points[q.top()]);
            q.pop();
        }

        return result;
    }
};
