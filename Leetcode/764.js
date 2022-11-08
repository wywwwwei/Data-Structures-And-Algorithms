/**
 * 764. 最大加号标志
 * link：https://leetcode.cn/problems/largest-plus-sign/
 */

/**
 * @param {number} n
 * @param {number[][]} mines
 * @return {number}
 */
var orderOfLargestPlusSign = function (n, mines) {
    const dp = new Array(n).fill(0).map(() => new Array(n).fill(n));
    const zero = new Set();
    for (const mine of mines) {
        zero.add(mine[0] * n + mine[1]);
    }

    let result = 0;
    for (let i = 0; i < n; i++) {
        // left arrow
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (zero.has(i * n + j)) {
                count = 0;
            } else {
                count++;
            }
            dp[i][j] = Math.min(dp[i][j], count);
        }
        // right arrow
        count = 0;
        for (let j = n - 1; j >= 0; j--) {
            if (zero.has(i * n + j)) {
                count = 0;
            } else {
                count++;
            }
            dp[i][j] = Math.min(dp[i][j], count);
        }
    }
    for (let i = 0; i < n; i++) {
        // up arrow
        let count = 0;
        for (let j = 0; j < n; j++) {
            if (zero.has(j * n + i)) {
                count = 0;
            } else {
                count++;
            }
            dp[j][i] = Math.min(dp[j][i], count);
        }
        // down arrow
        count = 0;
        for (let j = n - 1; j >= 0; j--) {
            if (zero.has(j * n + i)) {
                count = 0;
            } else {
                count++;
            }
            dp[j][i] = Math.min(dp[j][i], count);
            result = Math.max(result, dp[j][i]);
        }
    }

    return result;
};