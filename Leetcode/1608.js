/**
 * 1608. 特殊数组的特征值
 * link：https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function (nums) {
    const n = nums.length;
    const sortNums = nums.sort((a, b) => (a - b));

    let prev = -1;
    for (let i = 0; i < n; i++) {
        const base = n - i;
        if (prev < base && sortNums[i] >= base) {
            return base;
        }
        prev = sortNums[i];
    }
    return -1;
};