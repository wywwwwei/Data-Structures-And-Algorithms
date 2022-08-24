/**
 * 658. 找到 K 个最接近的元素
 * link：https://leetcode.cn/problems/find-k-closest-elements/
 */

/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findClosestElements = function (arr, k, x) {
    const sortArray = [...arr];
    sortArray.sort((a, b) => {
        const diff1 = Math.abs(a - x), diff2 = Math.abs(b - x);
        return diff1 === diff2 ? a - b : diff1 - diff2;
    });
    return sortArray.slice(0, k).sort((a, b) => (a - b));
}; 