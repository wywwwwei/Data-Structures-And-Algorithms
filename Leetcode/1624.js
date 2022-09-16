/**
 * 1624. 两个相同字符之间的最长子字符串
 * link：https://leetcode.cn/problems/largest-substring-between-two-equal-characters/
 */

/**
 * @param {string} s
 * @return {number}
 */
var maxLengthBetweenEqualCharacters = function (s) {
    const count = new Array(26).fill(-1);
    const n = s.length;
    let result = -1;
    for (let i = 0; i < n; i++) {
        const chIndex = s.charCodeAt(i) - "a".charCodeAt(0);
        const lastIndex = count[chIndex];
        if (lastIndex >= 0) {
            result = Math.max(result, i - lastIndex - 1);
        } else {
            count[chIndex] = i;
        }
    }
    return result;
};