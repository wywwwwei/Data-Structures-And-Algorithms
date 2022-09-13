/**
 * 1619. 删除某些元素后的数组均值
 * link：https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var trimMean = function (arr) {
    const sortArr = arr.sort((a, b) => (a - b));
    const n = arr.length;
    let sum = 0;
    for (let i = n / 20; i < 19 * n / 20; i++) {
        sum += sortArr[i];
    }
    return sum / (n * 9 / 10);
};