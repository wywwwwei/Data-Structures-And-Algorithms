/**
 * 768. 最多能完成排序的块 II
 * link：https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function (arr) {
    const stack = [];
    for (const num of arr) {
        const n = stack.length;
        if (n === 0 || num >= stack[n - 1]) {
            stack.push(num);
        } else {
            const maxVal = stack.pop();
            while (stack.length > 0 && num < stack[stack.length - 1]) {
                stack.pop();
            }
            stack.push(maxVal);
        }
    }
    return stack.length;
};