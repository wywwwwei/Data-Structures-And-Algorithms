/**
 * 1668. 最大重复子字符串
 * link：https://leetcode.cn/problems/maximum-repeating-substring/
 */

/**
 * @param {string} sequence
 * @param {string} word
 * @return {number}
 */
var maxRepeating = function (sequence, word) {
    const m = word.length;
    const n = sequence.length;
    if (m > n) {
        return 0;
    }

    const dp = new Array(n - m + 1).fill(0);
    for (let i = 0; i <= n - m; i++) {
        if (sequence.substring(i, i + m) === word) {
            dp[i] = (i - m >= 0 ? dp[i - m] : 0) + 1;
        }
    }
    return Math.max(...dp);
};