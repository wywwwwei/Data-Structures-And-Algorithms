/**
 * 901. 股票价格跨度
 * link：https://leetcode.cn/problems/online-stock-span/
 */

var StockSpanner = function () {
    this.store = [];
};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function (price) {
    this.store.push(price);
    let result = 0;
    const n = this.store.length;
    for (let i = n - 1; i >= 0; i--) {
        if (this.store[i] <= price) {
            result++;
        } else {
            break;
        }
    }
    return result;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */