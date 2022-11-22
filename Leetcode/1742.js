/**
 * 1742. 盒子中小球的最大数量
 * link：https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/
 */

/**
 * @param {number} lowLimit
 * @param {number} highLimit
 * @return {number}
 */
var countBalls = function (lowLimit, highLimit) {
    const count = new Array(46).fill(0);
    let lastValue = -1;
    const calc = function (num) {
        let result = 0;
        for (const ch of num.toString()) {
            result += ch.charCodeAt(0) - "0".charCodeAt(0);
        }
        return result;
    }

    for (let i = lowLimit; i <= highLimit; i++) {
        if (lastValue === -1 || i % 10 === 0) {
            lastValue = calc(i);
        } else {
            lastValue += 1;
        }
        count[lastValue]++;
    }

    return Math.max(...count);
};