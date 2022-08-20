/**
 * 1455. 检查单词是否为句中其他单词的前缀
 * link：https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 */

/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function (sentence, searchWord) {
    const words = sentence.split(" ");
    const n = words.length;
    for (let i = 0; i < n; i++) {
        if (words[i].startsWith(searchWord)) {
            return i;
        }
    }
    return -1;
};