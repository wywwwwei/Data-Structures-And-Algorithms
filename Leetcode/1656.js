/**
 * 1656. 设计有序流
 * link：https://leetcode.cn/problems/design-an-ordered-stream/
 */

/**
 * @param {number} n
 */
var OrderedStream = function (n) {
    this.store = new Array(n);
    this.position = 0;
};

/** 
 * @param {number} idKey 
 * @param {string} value
 * @return {string[]}
 */
OrderedStream.prototype.insert = function (idKey, value) {
    this.store[idKey - 1] = value;
    const n = this.store.length, start = this.position;
    while (this.position <= n) {
        if (this.position >= n || !this.store[this.position]) {
            const result = this.store.slice(start, this.position);
            return result ? result : [];
        }
        this.position++;
    }
    return [];
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * var obj = new OrderedStream(n)
 * var param_1 = obj.insert(idKey,value)
 */