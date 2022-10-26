/**
 * 1822. 数组元素积的符号
 * link：https://leetcode.cn/problems/sign-of-the-product-of-an-array/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var arraySign = function (nums) {
    let positive = true;
    for (const num of nums) {
        if (num === 0) {
            return 0;
        }
        if (num < 0) {
            positive = !positive;
        }
    }
    return positive ? 1 : -1;
};