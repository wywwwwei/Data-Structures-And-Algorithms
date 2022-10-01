/**
 * 777. 在LR字符串中交换相邻字符
 * link：https://leetcode.cn/problems/swap-adjacent-in-lr-string/
 */

/**
 * @param {string} start
 * @param {string} end
 * @return {boolean}
 */
var canTransform = function (start, end) {
    const n = start.length;
    let startIndex = 0, endIndex = 0;
    while (true) {
        while (startIndex < n && start[startIndex] === 'X') {
            startIndex++;
        }
        while (endIndex < n && end[endIndex] === 'X') {
            endIndex++;
        }
        if (startIndex >= n || endIndex >= n) {
            break;
        }
        const s = start[startIndex], e = end[endIndex];
        if (s != e) {
            return false;
        }
        if ((s === "L" && startIndex < endIndex) || (s === "R" && startIndex > endIndex)) {
            return false;
        }
        startIndex++;
        endIndex++;
    }
    while (startIndex < n) {
        if (start[startIndex] != "X") {
            return false;
        }
    }
    while (endIndex < n) {
        if (end[endIndex] != "X") {
            return false;
        }
    }
    return true;
};