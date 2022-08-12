/**
 * 768. 最多能完成排序的块 II
 * link：https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
 */

/**
 * The condition that you can split: There will be no larger number than the current one.
 * So you need to keep track
 * 1. The number of numbers less than each number in arr
 * 2. The number of numbers that less than arr[i] between [0, i];
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function (arr) {
    const sortArr = [...arr].sort((a, b) => (a - b));
    let count = 0;
    let lessTable = new Map();
    const n = arr.length;
    for (let i = 0; i < n; i++) {
        if (i > 0 && sortArr[i] == sortArr[i - 1]) {
            count++;
            continue;
        }
        lessTable.set(sortArr[i], count);
        count++;
    }

    let maxVal = -1;
    let result = 0;
    count = 0;
    for (let i = 0; i < n; i++) {
        const num = arr[i];
        if (num > maxVal) {
            maxVal = num;
            count = i;
        } else if (num < maxVal) {
            count++;
        }
        if (lessTable.get(maxVal) <= count) {
            result++;
        }
    }
    return result;
};