/**
 * 902. 最大为 N 的数字组合
 * link：https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/
 */

/**
 * @param {string[]} digits
 * @param {number} n
 * @return {number}
 */
 var atMostNGivenDigitSet = function (digits, n) {
    let len = 0;
    for (let i = n; i > 0; i = Math.floor(i / 10)) {
        len++;
    }

    // Get the number of numbers that have less digits than n
    let result = 0;
    const count = digits.length;
    for (let i = 1; i < len; i++) {
        result += Math.pow(count, i);
    }

    // Get the number of numbers that have the same digits with n
    const findCount = function (num, bits) {
        if (bits === 0) {
            return 1;
        }
        const base = Math.pow(10, bits - 1), countbase = Math.pow(count, bits - 1);
        const bit = Math.floor(num / base), remain = num % base;
        let result = 0;
        for (let i = 0; i < count; i++) {
            const digit = +(digits[i]);
            if (digit > bit) {
                break;
            }
            result += (digit === bit) ? findCount(remain, bits - 1) : countbase;
        }
        return result;
    }

    return result + findCount(n, len);
};