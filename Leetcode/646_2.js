/**
 * 646. 最长数对链
 * link：https://leetcode.cn/problems/maximum-length-of-pair-chain/
 */

/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function (pairs) {
    const n = pairs.length;
    const sortPairs = pairs.sort((a, b) => (a[0] - b[0]));
    const dp = new Array(n).fill(1);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (sortPairs[j][1] < sortPairs[i][0]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
};