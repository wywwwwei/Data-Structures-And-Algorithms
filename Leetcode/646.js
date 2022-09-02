/**
 * 646. 最长数对链
 * link：https://leetcode.cn/problems/maximum-length-of-pair-chain/
 */

/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function (pairs) {
    const sortPairs = pairs.sort((pairA, pairB) => {
        return pairA[0] === pairB[0] ? (pairA[1] - pairA[0]) - (pairB[1] - pairB[0]) : pairA[0] - pairB[0];
    });
    const n = pairs.length;
    let result = 1, right = sortPairs[0][1];
    for (let i = 1; i < n; i++) {
        if (sortPairs[i][0] > right) {
            right = sortPairs[i][1];
            result++;
        } else if (sortPairs[i][1] < right) {
            right = sortPairs[i][1];
        }
    }
    return result;
};