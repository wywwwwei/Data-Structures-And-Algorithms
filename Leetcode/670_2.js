/**
 * 670. 最大交换
 * link：https://leetcode.cn/problems/maximum-swap/
 */

/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function (num) {
    const numStr = num.toString();
    const n = numStr.length;

    let maxIndex = n - 1;
    let swapMinIndex = -1, swapMaxIndex = -1;
    for (let i = n - 1; i >= 0; i--) {
        if (numStr[i] > numStr[maxIndex]) {
            maxIndex = i;
        } else if (numStr[i] < numStr[maxIndex]) {
            swapMinIndex = i;
            swapMaxIndex = maxIndex;
        }
    }

    if (swapMinIndex < 0) {
        return num;
    }
    return Number(numStr.substring(0, swapMinIndex) + numStr[swapMaxIndex] +
        numStr.substring(swapMinIndex + 1, swapMaxIndex) + numStr[swapMinIndex] +
        numStr.substring(swapMaxIndex + 1, n));

};