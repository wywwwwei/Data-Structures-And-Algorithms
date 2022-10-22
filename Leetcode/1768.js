/**
 * 1768. 交替合并字符串
 * link：https://leetcode.cn/problems/merge-strings-alternately/
 */

/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function (word1, word2) {
    let result = "";
    const length1 = word1.length, length2 = word2.length;
    let index = 0;
    for (index = 0; index < length1 && index < length2; index++) {
        result += word1[index] + word2[index];
    }
    result += word1.substring(index, length1);
    result += word2.substring(index, length2);
    return result;
};