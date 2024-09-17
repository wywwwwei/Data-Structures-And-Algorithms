/**
 * 815. 公交路线 Bus routes
 * link：https://leetcode.cn/problems/bus-routes
 */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.size();
        vector<vector<int>> map = vector(n, vector<int>(n));
        unordered_map<int, vector<int>> busNodes;
        for (int i = 0; i < n; ++i) {
            for (int route : routes[i]) {
                for (int node : busNodes[route]) {
                    map[i][node] = map[node][i] = 1;
                }
                busNodes[route].emplace_back(i);
            }
        }

        vector<int> distance(n, -1);
        queue<int> busQueue;
        for (int busNode : busNodes[source]) {
            distance[busNode] = 1;
            busQueue.push(busNode);
        }
        while (!busQueue.empty()) {
            int currentNode = busQueue.front();
            busQueue.pop();
            for (int i = 0; i < n; ++i) {
                if (map[currentNode][i] > 0 & distance[i] < 0) {
                    distance[i] = distance[currentNode] + 1;
                    busQueue.push(i);
                }
            }
        }
        int result = INT_MAX;
        for (int node : busNodes[target]) {
            if (distance[node] > 0) {
                result = min(result, distance[node]);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};