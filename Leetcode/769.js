/**
 * 769. 最多能完成排序的块
 * link：https://leetcode.cn/problems/max-chunks-to-make-sorted/
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function (arr) {
    const n = arr.length;

    let result = 0;
    let mask = 0;
    for (let i = 0; i < n; i++) {
        mask |= (1 << arr[i]);
        if (mask === ((1 << (i + 1)) - 1)) {
            result++;
        }
    }

    return result;
};