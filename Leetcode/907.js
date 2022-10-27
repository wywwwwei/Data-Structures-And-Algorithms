/**
 * 907. 子数组的最小值之和
 * link：https://leetcode.cn/problems/sum-of-subarray-minimums/
 */

/**
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function (arr) {
    const n = arr.length;

    const monoStack = [];
    const left = new Array(n), right = new Array(n);
    for (let i = 0; i < n; i++) {
        while (monoStack.length > 0 && arr[monoStack[monoStack.length - 1]] >= arr[i]) {
            monoStack.pop();
        }
        left[i] = monoStack.length > 0 ? i - monoStack[monoStack.length - 1] : i + 1;
        monoStack.push(i);
    }
    monoStack.splice(0, monoStack.length);
    for (let i = n - 1; i >= 0; i--) {
        while (monoStack.length > 0 && arr[monoStack[monoStack.length - 1]] > arr[i]) {
            monoStack.pop();
        }
        right[i] = monoStack.length > 0 ? monoStack[monoStack.length - 1] - i : n - i;
        monoStack.push(i);
    }

    let result = 0;
    const mod = 1e9 + 7;
    for (let i = 0; i < n; i++) {
        result = (result + left[i] * right[i] * arr[i]) % mod;
    }
    return result;
};