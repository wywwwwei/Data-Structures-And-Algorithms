/**
 * 731. 我的日程安排表 II
 * link：https://leetcode.cn/problems/my-calendar-ii/
 */

var MyCalendarTwo = function () {
    this.booked = [];
    this.overlaps = [];
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendarTwo.prototype.book = function (start, end) {
    for (const overlap of this.overlaps) {
        if (!(start >= overlap[1] || end <= overlap[0])) {
            return false;
        }
    }
    for (const book of this.booked) {
        if (!(start >= book[1] || end <= book[0])) {
            this.overlaps.push([Math.max(start, book[0]), Math.min(end, book[1])]);
        }
    }
    this.booked.push([start, end]);
    return true;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * var obj = new MyCalendarTwo()
 * var param_1 = obj.book(start,end)
 */