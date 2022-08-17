/**
 * 1224. 最大相等频率
 * link：https://leetcode.cn/problems/maximum-equal-frequency/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxEqualFreq = function (nums) {
    const timesMap = new Map(); // Record occurrences -> num
    const countMap = new Map(); // Records num -> occurrences
    let result = 0, maxTimes = 0;
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];

        let times = countMap.get(num) ?? 0;
        if (times > 0) {
            timesMap.set(times, timesMap.get(times) - 1);
        }
        times++;
        timesMap.set(times, (timesMap.get(times) ?? 0) + 1);
        maxTimes = Math.max(maxTimes, times);

        countMap.set(num, times);
        const find = maxTimes === 1 ||
            timesMap.get(maxTimes) === 1 && timesMap.get(maxTimes) * maxTimes + timesMap.get(maxTimes - 1) * (maxTimes - 1) === i + 1 ||
            timesMap.get(maxTimes) * maxTimes + 1 === i + 1 && timesMap.get(1) === 1;
        if (find) {
            result = Math.max(result, i + 1);
        }
    }
    return result;
};