/**
 * 1331. 数组序号转换
 * link：https://leetcode.cn/problems/rank-transform-of-an-array/
 */

/**
 * @param {number[]} arr
 * @return {number[]}
 */
 var arrayRankTransform = function (arr) {
    const arrCopy = [...arr];
    arrCopy.sort((a, b) => a - b);

    const n = arrCopy.length;
    const sequenceMap = new Map();
    let sequence = 1;
    for (let i = 0; i < n; i++) {
        if (i > 0 && arrCopy[i] === arrCopy[i - 1]) {
            continue;
        }
        sequenceMap.set(arrCopy[i], sequence);
        sequence++;
    }

    const answer = Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        answer[i] = sequenceMap.get(arr[i]);
    }

    return answer;
};