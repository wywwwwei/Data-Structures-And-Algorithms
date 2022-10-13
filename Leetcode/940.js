/**
 * 940. 不同的子序列 II
 * link：https://leetcode.cn/problems/distinct-subsequences-ii/
 */

var distinctSubseqII = function (s) {
    const MOD = 1000000007;

    const count = new Array(26).fill(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        let total = 1;
        for (let j = 0; j < 26; ++j) {
            total = (total + count[j]) % MOD;
        }
        count[s[i].charCodeAt() - 'a'.charCodeAt()] = total;
    }

    let result = 0;
    for (let i = 0; i < 26; ++i) {
        result = (result + count[i]) % MOD;
    }
    return result;
};