/**
 * 面试题 01.02. 判定是否互为字符重排
 * link：https://leetcode.cn/problems/check-permutation-lcci/
 */

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function (s1, s2) {
    if (s1.length != s2.length) {
        return false;
    }
    const count = new Map();
    for (const ch of s1) {
        const num = count.has(ch) ? count.get(ch) : 0;
        count.set(ch, num + 1);
    }
    for (const ch of s2) {
        if (!count.has(ch)) {
            return false;
        }
        const num = count.get(ch) - 1;
        if (num === 0) {
            count.delete(ch);
        } else {
            count.set(ch, num);
        }
    }
    return true;
};