/**
 * 698. 划分为k个相等的子集
 * link：https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canPartitionKSubsets = function (nums, k) {
    const n = nums.length;
    const sum = nums.reduce((previousValue, currentValue) => (previousValue + currentValue));
    if (sum % k !== 0) {
        return false;
    }
    const partialSum = sum / k;
    const sortArray = nums.sort((a, b) => (b - a));
    if (sortArray[sortArray.length - 1] > partialSum) {
        return false;
    }
    const result = new Array(k).fill(0);
    const dfs = function (index) {
        if (index >= n) {
            return true;
        }
        for (let i = 0; i < k; i++) {
            // 第1个球只需要尝试第一个桶
            if (index === 0 && i > 0) {
                break;
            }
            // 超出平均值
            if (result[i] + nums[index] > partialSum) {
                continue;
            }
            // 如果元素和相等，那么选择放入上一个桶和选择当前桶的结果是一致的
            if (i > 0 && result[i] === result[i - 1]) {
                continue;
            }
            result[i] += nums[index];
            if (dfs(index + 1)) {
                return true;
            }
            result[i] -= nums[index];
        }
        return false;
    }
    return dfs(0);
};