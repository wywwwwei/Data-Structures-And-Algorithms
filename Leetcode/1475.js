/**
 * 1475. 商品折扣后的最终价格
 * link：https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/
 */

/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function (prices) {
    const n = prices.length;
    const result = [...prices];
    const stack = [];

    for (let i = 0; i < n; i++) {
        while (stack.length > 0 && prices[stack[stack.length - 1]] >= prices[i]) {
            result[stack.pop()] -= prices[i];
        }
        stack.push(i);
    }

    return result;
};