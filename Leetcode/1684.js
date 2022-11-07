/**
 * 1684. 统计一致字符串的数目
 * link：https://leetcode.cn/problems/count-the-number-of-consistent-strings/
 */

/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function (allowed, words) {
    let allowedChar = 0;
    for (let i = 0; i < allowed.length; i++) {
        allowedChar += (1 << (allowed.charCodeAt(i) - "a".charCodeAt(0)));
    }
    let result = 0;
    for (const word of words) {
        let mask = 0;
        for (let i = 0; i < word.length; i++) {
            mask |= (1 << (word.charCodeAt(i) - "a".charCodeAt(0)));
        }
        if ((mask | allowedChar) === allowedChar) {
            result++;
        }
    }
    return result;
};