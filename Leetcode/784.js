/**
 * 784. 字母大小写全排列
 * link：https://leetcode.cn/problems/letter-case-permutation/
 */

/**
 * @param {string} s
 * @return {string[]}
 */
var letterCasePermutation = function (s) {
    const isAlpha = function (ch) {
        const code = ch.toLowerCase().charCodeAt(0);
        return (code >= 'a'.charCodeAt(0) && code <= 'z'.charCodeAt(0))
    }

    let result = [];
    const n = s.length;
    let currentResult = new Array(n);
    const dfs = function (index) {
        while (index < n && !isAlpha(s[index])) {
            currentResult[index] = s[index];
            index++;
        }
        if (index >= n) {
            result.push(currentResult.join(''));
            return;
        }
        currentResult[index] = s[index].toLowerCase();
        dfs(index + 1);

        currentResult[index] = s[index].toUpperCase();
        dfs(index + 1);
    }

    dfs(0);
    return result;
};