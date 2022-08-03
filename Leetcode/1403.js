/**
 * 1403. 非递增顺序的最小子序列
 * link：https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var minSubsequence = function (nums) {
    nums.sort((a, b) => (b - a));
    const n = nums.length;

    const sum = nums.reduce((previousValue, currentValue) => (previousValue + currentValue), 0);
    let currentSum = 0;
    for (let i = 0; i < n; i++) {
        currentSum += nums[i];
        if (currentSum > sum - currentSum) {
            return nums.slice(0, i + 1);
        }
    }

    return [];
};