/**
 * 2848. 与车相交的点 Points that intersect with cars
 * link：https://leetcode.cn/problems/points-that-intersect-with-cars
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int numberOfPoints(vector<vector<int>> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end(), [](const vector<int> &l, const vector<int> &r) {
            if (l[0] == r[0]) {
                return l[1] < r[1];
            }
            return l[0] < r[0];
        });

        int result = 0;
        int left = nums[0][0], right = nums[0][1];
        for (int i = 1; i < n; ++i) {
            if (nums[i][0] > right) {
                result += right - left + 1;
                left = nums[i][0];
                right = nums[i][1];
            } else {
                right = max(right, nums[i][1]);
            }
        }
        result += right - left + 1;
        return result;
    }
};