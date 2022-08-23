/**
 * 1460. 通过翻转子数组使两个数组相等
 * link：https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 */

/**
 * @param {number[]} target
 * @param {number[]} arr
 * @return {boolean}
 */
var canBeEqual = function (target, arr) {
    const count = new Array(1001).fill(0);
    for (const num of target) {
        count[num]++;
    }
    for (const num of arr) {
        count[num]--;
    }
    for (const num of count) {
        if (num != 0) {
            return false;
        }
    }
    return true;
};