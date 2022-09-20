/**
 * 56. 合并区间
 * link：https://leetcode.cn/problems/merge-intervals/
 */

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    const n = intervals.length;
    if (n <= 0) {
        return [];
    }

    const sortIntervals = intervals.sort((a, b) => {
        return a[0] - b[0];
    });
    const result = [];
    for (let i = 0; i < n - 1; i++) {
        if (sortIntervals[i][1] >= sortIntervals[i + 1][0]) {
            sortIntervals[i + 1][0] = sortIntervals[i][0];
            sortIntervals[i + 1][1] = Math.max(sortIntervals[i][1], sortIntervals[i + 1][1]);
        } else {
            result.push(sortIntervals[i]);
        }
    }
    result.push(sortIntervals[n - 1]);
    return result;
};