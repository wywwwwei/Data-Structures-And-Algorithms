/**
 * 2376. 统计特殊整数 Count special integers
 * link：https://leetcode.cn/problems/count-special-integers
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    unordered_map<int, int> memo;

    int countSpecialNumbers(int n) {
        string nStr = to_string(n);

        int result = 0;
        int current = 9;
        for (int i = 0; i < nStr.length() - 1; ++i) {
            result += current;
            current *= (9 - i);
        }
        result += dp(0, false, nStr);
        return result;
    }

    int dp(int mask, bool prefixSmaller, const string &nStr) {
        if (__builtin_popcount(mask) == nStr.size()) {
            return 1;
        }
        int key = mask * 2 + (prefixSmaller ? 1 : 0);
        if (!memo.count(key)) {
            int res = 0;
            int lowerBound = mask == 0 ? 1 : 0;
            int upperBound = prefixSmaller ? 9 : nStr[__builtin_popcount(mask)] - '0';
            for (int i = lowerBound; i <= upperBound; i++) {
                if (((mask >> i) & 1) == 0) {
                    res += dp(mask | (1 << i), prefixSmaller || i < upperBound, nStr);
                }
            }
            memo[key] = res;
        }
        return memo[key];
    }
};