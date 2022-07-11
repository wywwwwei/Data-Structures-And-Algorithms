/**
 * 1252. 奇数值单元格的数目
 * link：https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/
 */

/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function (m, n, indices) {
    const row = Array(m).fill(0);
    const column = Array(n).fill(0);
    for (const indice of indices) {
        row[indice[0]]++;
        column[indice[1]]++;
    }

    // let result = 0;
    // for (let i = 0; i < m; i++) {
    //     for (let j = 0; j < n; j++) {
    //         result += ((row[i] + column[j]) & 1) > 0 ? 1 : 0;
    //     }
    // }

    const count = function (array, predicate) {
        let result = 0;
        for (const element of array) {
            if (predicate(element)) {
                result++;
            }
        }
        return result;
    }

    const oddX = count(row, (element) => (element & 1 > 0));
    const oddY = count(column, (element) => (element & 1 > 0));
    return oddX * (n - oddY) + oddY * (m - oddX);
};