/**
 * 面试题 17.09. 第 k 个数
 * link：https://leetcode.cn/problems/get-kth-magic-number-lcci/
 */

/**
 * @param {number} k
 * @return {number}
 */
var getKthMagicNumber = function (k) {
    const dp = new Array(k);
    dp[0] = 1;

    let index3 = 0, index5 = 0, index7 = 0;
    for (let i = 1; i < k; i++) {
        const value3 = dp[index3] * 3;
        const value5 = dp[index5] * 5;
        const value7 = dp[index7] * 7;
        dp[i] = Math.min(value3, Math.min(value5, value7));
        if (dp[i] === value3) {
            index3++;
        }
        if (dp[i] === value5) {
            index5++;
        }
        if (dp[i] === value7) {
            index7++;
        }
    }

    return dp[k - 1];
};