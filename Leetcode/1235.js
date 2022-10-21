/**
 * 1235. 规划兼职工作
 * link：https://leetcode.cn/problems/maximum-profit-in-job-scheduling/
 */

/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number[]} profit
 * @return {number}
 */
var jobScheduling = function (startTime, endTime, profit) {
    const n = startTime.length;
    const jobs = new Array(n).fill(0).map((_, idx) => [startTime[idx], endTime[idx], profit[idx]]).sort((a, b) => (a[1] - b[1]));
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        const k = binarySearchStartTime(jobs, 0, i - 1, jobs[i - 1][0]);
        dp[i] = Math.max(dp[i - 1], dp[k] + jobs[i - 1][2]);
    }
    return dp[n];
};

const binarySearchStartTime = function (array, start, end, target) {
    let left = start, right = end;
    while (left < right) {
        const mid = left + ((right - left) >> 1);
        if (target < array[mid][1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}