/**
 * 1784. 检查二进制字符串字段
 * link：https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var checkOnesSegment = function (s) {
    return s.indexOf("01") === -1;
};