/**
 * 1470. 重新排列数组
 * link：https://leetcode.cn/problems/shuffle-the-array/
 */

/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function (nums, n) {
    let result = new Array(n * 2).fill(0);
    for (let i = 0; i < n; i++) {
        result[i * 2] = nums[i];
        result[i * 2 + 1] = nums[i + n];
    }
    return result;
};