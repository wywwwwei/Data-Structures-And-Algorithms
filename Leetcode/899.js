/**
 * 899. 有序队列
 * link：https://leetcode.cn/problems/orderly-queue/
 */

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function (s, k) {
    if (k === 1) {
        let ans = s;
        const n = s.length;
        for (let i = 0; i < s.length - 1; ++i) {
            s = s.substring(1, n) + s[0];
            ans = ans < s ? ans : s;
        }
        return ans;
    }
    return [...s].sort().join('');
};