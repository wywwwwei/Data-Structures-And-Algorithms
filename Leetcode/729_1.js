/**
 * 729. 我的日程安排表 I
 * link：https://leetcode.cn/problems/my-calendar-i/
 */

var MyCalendar = function () {
    this.tree = new Set();
    this.lazy = new Set();
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function (start, end) {
    if (this.query(start, end - 1, 0, 1e9, 1)) {
        return false;
    }
    this.update(start, end - 1, 0, 1e9, 1);
    return true;
};

MyCalendar.prototype.query = function (start, end, l, r, idx) {
    if (start > r || end < l) {
        return false;
    }
    if (this.lazy.has(idx)) {
        return true;
    }
    if (start <= l && end >= r) {
        return this.tree.has(idx);
    }
    const mid = (l + r) >> 1;
    return this.query(start, end, l, mid, 2 * idx) || this.query(start, end, mid + 1, r, 2 * idx + 1);
}

MyCalendar.prototype.update = function (start, end, l, r, idx) {
    if (start > r || end < l) {
        return;
    }
    if (start <= l && end >= r) {
        this.tree.add(idx);
        this.lazy.add(idx);
        return;
    }
    const mid = (l + r) >> 1;
    this.update(start, end, l, mid, 2 * idx);
    this.update(start, end, mid + 1, r, 2 * idx + 1);
    this.tree.add(idx);
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */