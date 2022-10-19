/**
 * 779. 第K个语法符号
 * link：https://leetcode.cn/problems/k-th-symbol-in-grammar/
 */

/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var kthGrammar = function (n, k) {
    if (n === 1) {
        return 0;
    }
    if (k % 2 === 0) {
        return kthGrammar(n - 1, Math.floor((k + 1) / 2)) === 1 ? 0 : 1;
    } else {
        return kthGrammar(n - 1, Math.floor((k + 1) / 2)) === 1 ? 1 : 0;
    }
};