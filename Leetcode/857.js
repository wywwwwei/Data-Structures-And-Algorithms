/**
 * 857. 雇佣 K 名工人的最低成本
 * link：https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/
 */

/**
 * wage[i] <= totalCost * (quality[i] / totalQuality)
 * totalCost >= ( wage[i] / quality[i] ) * totalQuality
 * 
 * So select the less totalQuality and less ( wage[i] / quality[i] )
 */

/**
 * @param {number[]} quality
 * @param {number[]} wage
 * @param {number} k
 * @return {number}
 */
var mincostToHireWorkers = function (quality, wage, k) {
    const n = quality.length;
    const index = new Array(n).fill(0).map((_, i) => i);
    index.sort((a, b) => {
        return quality[b] * wage[a] - quality[a] * wage[b];
    });

    let result = Number.MAX_VALUE;
    let totalQuality = 0;
    const pq = new MaxPriorityQueue();
    for (let i = 0; i < k - 1; i++) {
        totalQuality += quality[index[i]];
        pq.enqueue(quality[index[i]]);
    }
    for (let i = k - 1; i < n; i++) {
        const pos = index[i];
        totalQuality += quality[pos];
        result = Math.min(result, totalQuality * (wage[pos] / quality[pos]));

        pq.enqueue(quality[pos]);
        totalQuality -= pq.dequeue().element;
    }
    return result;
};