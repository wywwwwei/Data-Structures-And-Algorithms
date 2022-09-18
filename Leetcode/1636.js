/**
 * 1636. 按照频率将数组升序排序
 * link：https://leetcode.cn/problems/sort-array-by-increasing-frequency/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function (nums) {
    const count = new Map();
    for (const num of nums) {
        const freq = count.get(num) ?? 0;
        count.set(num, freq + 1);
    }
    return nums.sort((a, b) => {
        const freqA = count.get(a);
        const freqB = count.get(b);
        if (freqA === freqB) {
            return b - a;
        }
        return freqA - freqB;
    });
};