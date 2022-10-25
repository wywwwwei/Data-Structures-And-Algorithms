/**
 * 862. 和至少为 K 的最短子数组
 * link：https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var shortestSubarray = function (nums, k) {
    const n = nums.length;
    const preSum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    let result = n + 1;
    const queue = [0];
    for (let i = 1; i <= n; i++) {
        const currentSum = preSum[i];
        while (queue.length > 0 && currentSum - preSum[queue[0]] >= k) {
            result = Math.min(result, i - queue[0]);
            queue.shift();
        }
        while (queue.length > 0 && currentSum <= preSum[queue[queue.length - 1]]) {
            queue.pop();
        }
        queue.push(i);
    }
    return result < n + 1 ? result : -1;
};