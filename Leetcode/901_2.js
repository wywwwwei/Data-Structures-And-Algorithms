/**
 * 901. 股票价格跨度
 * link：https://leetcode.cn/problems/online-stock-span/
 */

var StockSpanner = function () {
    this.store = [];
    this.last = [];
};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function (price) {
    this.store.push(price);
    const n = this.store.length;

    let result = 0, index = n - 1;
    this.last.push(index);
    while (index >= 0) {
        if (this.store[index] <= price) {
            result += (index - this.last[index]) + 1;
            index = this.last[index];
        } else {
            break;
        }
        index--;
    }
    this.last[n - 1] = index + 1;
    return result;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */