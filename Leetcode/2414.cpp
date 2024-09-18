/**
 * 2414. 最长的字母序连续子字符串的长度 Length of the longest alphabetical continuous substring
 * link：https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestContinuousSubstring(string s) {
        // slide window solution
        // int n = s.length();
        // int result = 0;
        // int left = 0, right = 0;
        // while (left < n) {
        //     ++right;
        //     while (right < n && s[right] == s[right - 1] + 1) {
        //         ++right;
        //     }
        //     result = max(result, right - left);
        //     left = right;
        // }
        // return result;

        int current = 1;
        int result = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1] + 1) {
                ++current;
            } else {
                result = max(result, current);
                current = 1;
            }
        }
        result = max(result, current);
        return result;
    }
};