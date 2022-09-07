/**
 * 667. 优美的排列 II
 * link：https://leetcode.cn/problems/beautiful-arrangement-ii/
 */

/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var constructArray = function (n, k) {
    const result = new Array(n).fill(0);
    let index = 0;
    for (let i = 1; i < n - k; i++) {
        result[index] = i;
        index++;
    }
    for (let i = n - k, j = n; i <= j; i++, j--) {
        result[index] = i;
        index++;
        if (i != j) {
            result[index] = j;
            index++;
        }
    }
    return result;
};