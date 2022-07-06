/**
 * 648. 单词替换
 * link：https://leetcode.cn/problems/replace-words/
 */

/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function (dictionary, sentence) {
    const wordRoot = new Set();
    let maxRootLen = 0;
    for (const root of dictionary) {
        maxRootLen = Math.max(maxRootLen, root.length);
        wordRoot.add(root);
    }
    const words = sentence.split(' ');
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        for (let j = 1; j <= Math.min(maxRootLen, word.length); j++) {
            const partWord = word.substring(0, j);
            if (wordRoot.has(partWord)) {
                words[i] = partWord;
                break;
            }
        }
    }
    return words.join(' ');
};