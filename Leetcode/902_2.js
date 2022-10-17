/**
 * 902. 最大为 N 的数字组合
 * link：https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/
 */

/**
 * @param {string[]} digits
 * @param {number} n
 * @return {number}
 */
var atMostNGivenDigitSet = function (digits, n) {
    const target = '' + n;
    const m = digits.length, n = target.length;
    const dp = new Array(n + 1).fill(0).map(() => new Array(2).fill(0));
    dp[0][1] = 1;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < m; j++) {
            if (digits[j][0] === s[i - 1]) {
                dp[i][1] = dp[i - 1][1];
            } else if (digits[j][0] < s[i - 1]) {
                dp[i][0] += dp[i - 1][1];
            } else {
                break;
            }
        }
        if (i > 1) {
            dp[i][0] += m + dp[i - 1][0] * m;
        }
    }
    return dp[k][0] + dp[k][1];
};