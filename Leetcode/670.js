/**
 * 670. 最大交换
 * link：https://leetcode.cn/problems/maximum-swap/
 */

/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function (num) {
    const stack = [];
    const numStr = num.toString();
    const n = numStr.length;

    for (let i = 0; i < n; i++) {
        const val = + numStr[i];
        while (stack.length > 0 && val >= +numStr[stack[stack.length - 1]]) {
            stack.pop();
        }
        stack.push(i);
    }
    let lastIndex = 0;
    while (stack.length > 0) {
        const maxIndex = stack.shift();
        const maxVal = numStr[maxIndex];
        for (let i = lastIndex; i < maxIndex; i++) {
            if (+maxVal > +numStr[i]) {
                return Number(numStr.substring(0, i) + maxVal + numStr.substring(i + 1, maxIndex) + numStr[i]) + numStr.substring(maxIndex + 1, n);
            }
        }
        lastIndex = maxIndex;
    }
    return num;
};