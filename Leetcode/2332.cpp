/**
 * 2332. 坐上公交的最晚时间 The latest time to catch a bus
 * link：https://leetcode.cn/problems/the-latest-time-to-catch-a-bus
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int ptr = 0;
        int space = 0;
        for (int bus : buses) {
            space = capacity;
            while (space > 0 && ptr < passengers.size() && passengers[ptr] <= bus) {
                --space;
                ++ptr;
            }
        }

        --ptr;
        int last = space > 0 ? buses.back() : passengers[ptr];
        while (ptr >= 0 && passengers[ptr] == last) {
            --last;
            --ptr;
        }

        return last;
    }
};