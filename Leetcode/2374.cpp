/**
 * 2374. 边积分最高的节点 Node with highest edge score
 * link：https://leetcode.cn/problems/node-with-highest-edge-score
 */

#include <vector>

using namespace std;

class Solution {
  public:
    int edgeScore(vector<int> &edges) {
        int n = edges.size();
        vector<unsigned long long> result = vector(n, 0ULL);
        for (int i = 0; i < n; ++i) {
            result[edges[i]] += i;
        }
        return distance(result.begin(), max_element(result.begin(), result.end()));
    }
};