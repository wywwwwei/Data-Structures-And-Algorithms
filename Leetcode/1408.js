/**
 * 1408. 数组中的字符串匹配
 * link：https://leetcode.cn/problems/string-matching-in-an-array/
 */

/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function (words) {
    const result = [];
    const n = words.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i != j && words[j].includes(words[i])) {
                result.push(words[i]);
                break;
            }
        }
    }
    return result;
};