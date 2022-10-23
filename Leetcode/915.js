/**
 * 915. 分割数组
 * link：https://leetcode.cn/problems/partition-array-into-disjoint-intervals/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var partitionDisjoint = function (nums) {
    const n = nums.length;
    const minRight = new Array(n).fill(0);
    let minValue = Number.MAX_VALUE, maxValue = -1;
    for (let i = n - 1; i >= 0; i--) {
        minValue = Math.min(minValue, nums[i]);
        minRight[i] = minValue;
    }
    for (let i = 0; i < n - 1; i++) {
        maxValue = Math.max(maxValue, nums[i]);
        if (maxValue <= minRight[i + 1]) {
            return i + 1;
        }
    }
    return n;
};