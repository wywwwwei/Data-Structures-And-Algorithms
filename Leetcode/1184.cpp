/**
 * 1184. 公交站间的距离 Distance between bus stops
 * link：https://leetcode.cn/problems/distance-between-bus-stops
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start == destination) {
            return 0;
        }
        int n = distance.size();
        int result = 0;
        int sum = distance[start];
        for (int i = (start + 1) % n; i != start; i = (i + 1) % n) {
            if (i == destination) {
                result = sum;
            }
            sum += distance[i];
        }
        return min(result, sum - result);
    }
};