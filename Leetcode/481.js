/**
 * 481. 神奇字符串
 * link：https://leetcode.cn/problems/magical-string/
 */

/**
 * @param {number} n
 * @return {number}
 */
var magicalString = function (n) {
    const stack = [];
    let current = 0, result = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < (stack.length > i ? stack[i] : 1); j++) {
            stack.push(i % 2 === 0 ? 1 : 2);
        }
        if (i % 2 === 0) {
            result += Math.min(stack[i], n - current);
        }
        current += stack[i];
        if (current >= n) {
            break;
        }
    }
    return result;
};