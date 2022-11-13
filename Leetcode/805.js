/**
 * 805. 数组的均值分割
 * link：https://leetcode.cn/problems/split-array-with-same-average/
 */

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var splitArraySameAverage = function (nums) {
    const n = nums.length, m = Math.floor(n / 2);
    if (n <= 1) {
        return false;
    }

    const sum = nums.reduce((prev, cur) => (prev + cur));

    let isPossible = false;
    for (let i = 1; i <= m; i++) {
        if (sum * i % n === 0) {
            isPossible = true;
            break;
        }
    }
    if (!isPossible) {
        return false;
    }

    const dp = new Array(m + 1).fill(null).map(() => new Set());
    dp[0].add(0);
    for (const num of nums) {
        for (let i = m; i >= 1; i--) {
            for (const x of dp[i - 1]) {
                let curr = x + num;
                if (curr * n === sum * i) {
                    return true;
                }
                dp[i].add(curr);
            }
        }
    }
    return false;
};