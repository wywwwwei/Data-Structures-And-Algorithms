/**
 * 828. 统计子串中的唯一字符
 * link：https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/
 */

/**
 * @param {string} s
 * @return {number}
 */
var uniqueLetterString = function (s) {
    const n = s.length;
    const indexMap = new Map();
    for (let i = 0; i < n; i++) {
        const ch = s[i];
        if (!indexMap.has(ch)) {
            indexMap.set(ch, [-1]);
        }
        indexMap.get(ch).push(i);
    }
    let result = 0;
    indexMap.forEach((value) => {
        value.push(n);
        for (let i = 1; i < value.length - 1; i++) {
            result += (value[i] - value[i - 1]) * (value[i + 1] - value[i]);
        }
    });
    return result;
};