/**
 * 873. 最长的斐波那契子序列的长度
 * link：https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var lenLongestFibSubseq = function (arr) {
    const len = arr.length;
    const index = new Map();
    for (let i = 0; i < len; i++) {
        index.set(arr[i], i);
    }

    const dp = Array(len * len).fill(2);
    const arrayIndex = (a, b) => (a * len + b);
    let result = 0;
    for (let i = 2; i < len; i++) {
        for (let j = i - 1; j > 0; j--) {
            if (arr[j] * 2 <= arr[i]) {
                break;
            }
            const lastNumber = arr[i] - arr[j];
            if (index.has(lastNumber)) {
                dp[arrayIndex(j, i)] = Math.max(dp[arrayIndex(j, i)], dp[arrayIndex(index.get(lastNumber), j)] + 1);
                result = Math.max(result, dp[arrayIndex(j, i)]);
            }
        }
    }

    return result;
};