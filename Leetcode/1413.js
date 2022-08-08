/**
 * 1413. 逐步求和得到正数的最小值
 * link：https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minStartValue = function (nums) {
    let sum = 0, minSum = 0;
    for (const num of nums) {
        sum += num;
        minSum = Math.min(minSum, sum);
    }
    return 1 - minSum;
};