/**
 * 946. 验证栈序列
 * link：https://leetcode.cn/problems/validate-stack-sequences/
 */

/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function (pushed, popped) {
    const stack = [];
    const n = pushed.length;

    for (let i = 0, j = 0; i < n; i++) {
        stack.push(pushed[i]);
        while (stack.length > 0 && stack[stack.length - 1] === popped[j]) {
            stack.pop();
            j++;
        }
    }

    return stack.length === 0;
};