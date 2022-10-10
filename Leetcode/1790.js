/**
 * 1790. 仅执行一次字符串交换能否使两个字符串相等
 * link：https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/
 */

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var areAlmostEqual = function (s1, s2) {
    const n = s1.length;
    const diff = [];

    for (let i = 0; i < n; i++) {
        if (s1[i] === s2[i]) {
            continue;
        }
        if (diff.length >= 2) {
            return false;
        }
        diff.push(i);
    }
    return diff.length === 0 || (diff.length === 2 && s1[diff[0]] === s2[diff[1]] && s1[diff[1]] === s2[diff[0]]);
};