/**
 * 1800. 最大升序子数组和
 * link：https://leetcode.cn/problems/maximum-ascending-subarray-sum/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAscendingSum = function (nums) {
    let result = 0;

    let currentSum = 0;
    let last = 0;
    for (const num of nums) {
        if (num > last) {
            currentSum += num;
        } else {
            result = Math.max(result, currentSum);
            currentSum = num;
        }
        last = num;
    }
    result = Math.max(result, currentSum);
    return result;
};