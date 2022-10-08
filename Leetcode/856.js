/**
 * 856. 括号的分数
 * link：https://leetcode.cn/problems/score-of-parentheses/
 */

/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function (s) {
    const n = s.length;
    let score = 0;
    let left = 0;
    let startIndex = 0;
    for (let i = 0; i < n; i++) {
        if (s[i] === '(') {
            if (left === 0) {
                startIndex = i;
            }
            left++;
        } else {
            left--;
            if (left === 0) {
                const substr = s.substring(startIndex + 1, i);
                if (substr === "") {
                    score += 1;
                } else {
                    score += 2 * scoreOfParentheses(substr);
                }
            }
        }
    }

    return score;
};