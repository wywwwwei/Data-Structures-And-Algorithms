/**
 * 1217. 玩筹码
 * link：https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position/
 */

/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function (position) {
    let oddCount = 0, evenCount = 0;
    for (const pos of position) {
        (pos & 1) ? oddCount++ : evenCount++;
    }
    return Math.min(oddCount, evenCount);

    // let oddCount = [...position].filter((pos) => (pos & 1)).length;
    // return Math.min(oddCount, position.length - oddCount);
};