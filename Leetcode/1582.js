/**
 * 1582. 二进制矩阵中的特殊位置
 * link：https://leetcode.cn/problems/special-positions-in-a-binary-matrix/
 */

/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSpecial = function (mat) {
    const rowCount = mat.length, colCount = mat[0].length;
    const rows = new Array(rowCount).fill(0), cols = new Array(colCount).fill(0);
    for (let i = 0; i < rowCount; i++) {
        for (let j = 0; j < colCount; j++) {
            rows[i] += mat[i][j];
            cols[j] += mat[i][j];
        }
    }
    let result = 0;
    for (let i = 0; i < rowCount; i++) {
        if (rows[i] !== 1) {
            continue;
        }
        for (let j = 0; j < colCount; j++) {
            if (cols[j] === 1 && mat[i][j] === 1) {
                result++;
            }
        }
    }
    return result;
};