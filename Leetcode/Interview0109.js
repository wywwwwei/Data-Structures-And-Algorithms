/**
 * 面试题 01.09. 字符串轮转
 * link：https://leetcode.cn/problems/string-rotation-lcci/
 */

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isFlipedString = function (s1, s2) {
    // return (s1.length === s2.length && (s1 + s1).indexOf(s2) !== -1);
    const n = s1.length;
    if (s2.length != n) {
        return false;
    }
    if (n === 0) {
        return true;
    }
    for (let i = 0; i < n; i++) {
        const str = s1.substring(i, n) + s1.substring(0, i);
        if (str === s2) {
            return true;
        }
    }
    return false;
};