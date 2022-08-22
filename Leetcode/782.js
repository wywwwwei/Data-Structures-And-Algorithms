/**
 * 782. 变为棋盘
 * link：https://leetcode.cn/problems/transform-to-chessboard/
 */

/**
 * @param {number[][]} board
 * @return {number}
 */
var movesToChessboard = function (board) {
    const n = board.length;

    let rowMask = 0, colMask = 0;
    for (let i = 0; i < n; i++) {
        rowMask |= board[0][i] << i;
        colMask |= board[i][0] << i;
    }
    const reverseRowMask = (2 ** n - 1) ^ rowMask;
    const reverseColMask = (2 ** n - 1) ^ colMask;

    let rowCount = 0, colCount = 0;
    for (let i = 0; i < n; i++) {
        let currentRowMask = 0, currentColMask = 0;
        for (let j = 0; j < n; j++) {
            currentRowMask |= board[i][j] << j;
            currentColMask |= board[j][i] << j;
        }
        // check row
        if (currentRowMask != rowMask && currentRowMask != reverseRowMask) {
            return -1;
        } else if (currentRowMask === rowMask) {
            rowCount++;
        }
        // check column
        if (currentColMask != colMask && currentColMask != reverseColMask) {
            return -1;
        } else if (currentColMask === colMask) {
            colCount++;
        }
    }
    const rowMoves = getMinMove(rowMask, rowCount, n);
    const colMoves = getMinMove(colMask, colCount, n);
    return (rowMoves == -1 || colMoves == -1) ? -1 : (rowMoves + colMoves); 
};

const getMinMove = function (mask, count, n) {
    const maskBitsCount = bitsCount(mask);
    // odd number of 1s
    if ((n & 1) === 1) {
        if (Math.abs(n - 2 * maskBitsCount) !== 1 || Math.abs(n - 2 * count) !== 1) {
            return -1;
        }
        // n = (2 * 1s + 1) such as 01010
        if (maskBitsCount === (n >> 1)) {
            return Math.floor(n / 2) - bitsCount(mask & 0xAAAAAAAA);
        } else {    // n = (2 * 1s - 1) such as 10101
            return Math.floor((n + 1) / 2) - bitsCount(mask & 0x55555555);
        }
    } else {
        if (maskBitsCount !== (n >> 1) || count !== (n >> 1)) {
            return -1;
        }
        const count0 = Math.floor(n / 2) - bitsCount(mask & 0xAAAAAAAA);
        const count1 = Math.floor(n / 2) - bitsCount(mask & 0x55555555);  
        return Math.min(count0, count1);
    }
}

const bitsCount = (num) => {
    return num.toString(2).split("0").join("").length;
}