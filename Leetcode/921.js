/**
 * 921. 使括号有效的最少添加
 * link：https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/
 */

/**
 * @param {string} s
 * @return {number}
 */
var minAddToMakeValid = function (s) {
    let leftCount = 0;
    let result = 0;
    for (const ch of s) {
        if (ch === "(") {
            leftCount++;
        } else {
            if (leftCount > 0) {
                leftCount--;
            } else {
                result++;
            }
        }
    }
    return result + leftCount;
};