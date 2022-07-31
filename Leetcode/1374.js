/**
 * 1374. 生成每种字符都是奇数个的字符串
 * link：https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/
 */

/**
 * @param {number} n
 * @return {string}
 */
var generateTheString = function (n) {
    if (n % 2 === 1) {
        return "a".repeat(n);
    }
    return "a".repeat(n - 1) + "b";
};