/**
 * 997. 找到小镇的法官 Find the town judge
 * link：https://leetcode.cn/problems/find-the-town-judge
 */

#include <vector>

using namespace std;

class Solution {
  public:
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<int> trustedRecord = vector(n + 1, 0);
        vector<int> trustRecord = vector(n + 1, 0);
        for (const auto &t : trust) {
            trustedRecord[t[1]]++;
            trustRecord[t[0]]++;
        }
        int result = -1;
        for (int i = 1; i <= n; ++i) {
            if (trustedRecord[i] == n - 1 && trustRecord[i] == 0) {
                result = i;
                break;
            }
        }
        return result;
    }
};