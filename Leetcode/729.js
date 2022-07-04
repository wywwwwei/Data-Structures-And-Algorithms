/**
 * 729. 我的日程安排表 I
 * link：https://leetcode.cn/problems/my-calendar-i/
 */

var MyCalendar = function () {
    this.book_times = [];
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function (start, end) {
    for (let i = 0; i < this.book_times.length; i++) {
        let book_time = this.book_times[i];
        if (end <= book_time[0]) {
            this.book_times.splice(i, 0, [start, end]);
            return true;
        }
        if (start < book_time[1]) {
            return false;
        }
    }
    this.book_times.push([start, end]);
    return true;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */