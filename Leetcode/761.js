/**
 * 761. 特殊的二进制序列
 * link：https://leetcode.cn/problems/special-binary-string/
 */

/**
 * 1. Every prefix of the binary string has at least as many 1's as 0's.
 *    => Begin with 1
 * 2. The number of 0's is equal to the number of 1's.
 *    => End with 1
 */

/**
 * @param {string} s
 * @return {string}
 */
var makeLargestSpecial = function (s) {
    const n = s.length;
    if (n <= 2) {
        return s;
    }
    let count = 0, left = 0;
    const parts = [];
    for (let i = 0; i < n; i++) {
        if (s[i] === '1') {
            count++;
        } else {
            count--;
            if (count === 0) {
                parts.push("1" + makeLargestSpecial(s.substring(left + 1, i)) + "0");
                left = i + 1;
            }
        }
    }
    parts.sort().reverse();
    return parts.join('');
};