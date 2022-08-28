/**
 * 793. 阶乘函数后 K 个零
 * link：https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/
 */

/**
 * @param {number} k
 * @return {number}
 */
var preimageSizeFZF = function (k) {
    const numberOfFactor5 = (k) => {
        if (k === 0) {
            return 0;
        }
        const coefficient = Math.floor(k / 5);
        return coefficient + numberOfFactor5(coefficient);
    }
    let left = 0, right = 5 * k;
    while (left < right) {
        let mid = Math.floor((left + right) / 2), tmp = numberOfFactor5(mid);
        if (tmp === k) {
            return 5;
        } else if (tmp < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return numberOfFactor5(left) === k ? 5 : 0;
};