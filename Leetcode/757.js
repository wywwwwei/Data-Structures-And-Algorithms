/**
 * 757. 设置交集大小至少为2
 * link：https://leetcode.cn/problems/set-intersection-size-at-least-two/
 */

/**
 * @param {number[][]} intervals
 * @return {number}
 */
var intersectionSizeTwo = function (intervals) {
    intervals.sort((a, b) => a[1] == b[1] ? b[0] - a[0] : a[1] - b[1])

    let l = intervals[0][1] - 1;
    let r = intervals[0][1];
    let result = 2;
    for (const interval of intervals) {
        if (l >= interval[0]) {
            continue;
        } else if (r >= interval[0]) {
            l = r;
            r = interval[1];
            result++;
        } else {
            l = interval[1] - 1;
            r = interval[1];
            result += 2;
        }
    }
    return result;
};