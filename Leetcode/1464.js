/**
 * 1464. 数组中两元素的最大乘积
 * link：https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function (nums) {
    // Method 1. Sort
    // const sortArray = nums.sort((a, b) => (a - b));
    // const n = nums.length;
    // return (nums[n - 1] - 1) * (nums[n - 2] - 1);

    // Method 2. Top K
    let maxVal = 0, secondMax = 0;
    for (const num of nums) {
        if (maxVal < num) {
            secondMax = maxVal;
            maxVal = num;
        } else {
            secondMax = Math.max(secondMax, num);
        }
    }
    return (maxVal - 1) * (secondMax - 1);
};