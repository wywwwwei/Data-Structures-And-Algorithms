/**
 * 1732. 找到最高海拔
 * link：https://leetcode.cn/problems/find-the-highest-altitude/
 */

/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function (gain) {
    let result = 0, current = 0;
    for (const value of gain) {
        current = current + value;
        result = Math.max(result, current);
    }
    return result;
};