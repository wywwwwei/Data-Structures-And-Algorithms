/**
 * 754. 到达终点数字
 * link：https://leetcode.cn/problems/reach-a-number/
 */

/**
 * @param {number} target
 * @return {number}
 */
var reachNumber = function (target) {
    target = Math.abs(target);
    let result = 0;
    while (target > 0) {
        result++;
        target -= result;
    }
    return (target % 2 === 0 ? result : result % 2 + result + 1);
};