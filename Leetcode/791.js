/**
 * 791. 自定义字符串排序
 * link：https://leetcode.cn/problems/custom-sort-string/
 */

/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function (order, s) {
    const charIndex = function (ch) {
        return ch.charCodeAt(0) - "a".charCodeAt(0);
    }

    const count = new Array(26).fill(0);
    for (const ch of s) {
        count[charIndex(ch)]++;
    }

    let result = "";
    for (const ch of order) {
        const idx = charIndex(ch);
        result += ch.repeat(count[idx]);
        count[idx] = 0;
    }

    for (let i = 0; i < count.length; i++) {
        result += String.fromCharCode("a".charCodeAt(0) + i).repeat(count[i]);
    }

    return result;
};