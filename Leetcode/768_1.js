/**
 * 768. 最多能完成排序的块 II
 * link：https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
 */

/**
 * Just make sure that arr[a...b] and sortArr[a...b] contain the same numbers.
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function (arr) {
    const sortArr = [...arr].sort((a, b) => (a - b));
    const table = new Map();
    const n = arr.length;
    let result = 0;
    for (let i = 0; i < n; i++) {
        const num = arr[i], sortNum = sortArr[i];
        table.set(num, (table.get(num) || 0) + 1);
        if (table.get(num) === 0) {
            table.delete(num);
        }
        table.set(sortNum, (table.get(sortNum) || 0) - 1);
        if (table.get(sortNum) === 0) {
            table.delete(sortNum);
        }
        if (table.size === 0) {
            result++;
        }
    }
    return result;
};