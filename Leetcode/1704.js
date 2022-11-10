/**
 * 1704. 判断字符串的两半是否相似
 * link：https://leetcode.cn/problems/determine-if-string-halves-are-alike/
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function (s) {
    const vowels = "aeiouAEIOU";

    const n = s.length;
    let left = 0, right = 0;
    for (let i = 0; i < n / 2; i++) {
        if (vowels.indexOf(s[i]) >= 0) {
            left++;
        }
    }
    for (let i = n - 1; i >= n / 2; i--) {
        if (vowels.indexOf(s[i]) >= 0) {
            right++;
        }
    }
    return left === right;
    // return (s.slice(0, s.length / 2).match(/[aeiou]/ig)?.length ?? 0) === (s.slice(s.length / 2).match(/[aeiou]/ig)?.length ?? 0);
};