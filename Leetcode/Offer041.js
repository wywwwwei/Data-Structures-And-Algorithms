/**
 * 剑指 Offer II 041. 滑动窗口的平均值
 * link：https://leetcode.cn/problems/qIsx9U/
 */

/**
 * Initialize your data structure here.
 * @param {number} size
 */
var MovingAverage = function (size) {
    this.size = size;
    this.store = [];
    this.sum = 0;
};

/** 
 * @param {number} val
 * @return {number}
 */
MovingAverage.prototype.next = function (val) {
    let n = this.store.length;
    if (n >= this.size) {
        this.sum -= this.store.shift();
        n--;
    }
    this.store.push(val);
    this.sum += val;
    n++;
    return this.sum / n;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = new MovingAverage(size)
 * var param_1 = obj.next(val)
 */