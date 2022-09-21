/**
 * 1640. 能否连接形成数组
 * link：https://leetcode.cn/problems/check-array-formation-through-concatenation/
 */

/**
 * @param {number[]} arr
 * @param {number[][]} pieces
 * @return {boolean}
 */
var canFormArray = function (arr, pieces) {
    const n = arr.length;
    const m = pieces.length;
    const index = new Map();
    for (let i = 0; i < m; i++) {
        index.set(pieces[i][0], i);
    }
    for (let i = 0; i < n;) {
        if (!index.has(arr[i])) {
            return false;
        }
        const piece = pieces[index.get(arr[i])];
        for (const num of piece) {
            if (num !== arr[i]) {
                return false;
            }
            i++;
        }
    }
    return true;
};