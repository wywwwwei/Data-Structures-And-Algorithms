/**
 * 1422. 分割字符串的最大得分
 * link：https://leetcode.cn/problems/maximum-score-after-splitting-a-string/
 */

/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function (s) {
    let leftScore = 0, rightScore = 0;

    for (const ch of s) {
        rightScore += Number(ch);
    }

    let result = 0;
    const n = s.length;
    for (let i = 0; i < n - 1; i++) {
        if (s[i] === "0") {
            leftScore++;
        } else {
            rightScore--;
        }
        result = Math.max(result, leftScore + rightScore);
    }

    return result;
};