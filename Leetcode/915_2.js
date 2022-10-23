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
    let maxLeft = nums[0], currentMaxLeft = maxLeft, result = 1;
    for (let i = 1; i < nums.length; i++) {
        const element = nums[i];
        currentMaxLeft = Math.max(currentMaxLeft, element);
        if (element < maxLeft) {
            maxLeft = currentMaxLeft;
            result = i + 1;
        }
    }
    return result;
};