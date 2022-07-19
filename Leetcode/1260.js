/**
 * 1260. 二维网格迁移
 * link：https://leetcode.cn/problems/shift-2d-grid/
 */

/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function (grid, k) {
    const m = grid.length, n = grid[0].length;
    const result = Array.from(Array(m), () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const index = (i * n + j + k) % (m * n);
            result[Math.floor(index / n)][index % n] = grid[i][j];
        }
    }
    return result;
};