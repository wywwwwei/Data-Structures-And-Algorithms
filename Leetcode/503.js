/**
 * 503. 下一个更大元素 II
 * link：https://leetcode.cn/problems/next-greater-element-ii/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function (nums) {
    const n = nums.length;
    const result = new Array(n).fill(-1);
    const stack = [];
    for (let i = 0; i < n * 2 - 1; i++) {
        while (stack.length && nums[stack[stack.length - 1]] < nums[i % n]) {
            result[stack.pop()] = nums[i % n];
        }
        stack.push(i % n);
    }
    return result;

};