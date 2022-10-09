/**
 * 801. 使序列递增的最小交换次数
 * link：https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/
 */

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minSwap = function (nums1, nums2) {
    // The test cases are generated so that the given input always makes it possible.
    // So there are only two cases
    // 1. nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]
    // 2. nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1]
    // 
    // Assume array dp, dp[i][0] means when i no swap ( 1 for swap ), 
    // the minimum number of needed operations that makes strictly increasing.
    // if case 1 is true and case 2 is false
    // dp[i][0] = dp[i - 1][0]
    // dp[i][1] = dp[i - 1][1] + 1
    // if case 2 is true and case 1 is false
    // dp[i][0] = dp[i - 1][1]
    // dp[i][1] = dp[i - 1][0] + 1
    const n = nums1.length;
    let last_no_swap = 0, last_swap = 1;
    let no_swap = 0, swap = 0;
    for (let i = 1; i < n; i++) {
        no_swap = Number.MAX_VALUE, swap = Number.MAX_VALUE;
        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
            no_swap = Math.min(no_swap, last_no_swap);
            swap = Math.min(swap, last_swap + 1);
        }
        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
            no_swap = Math.min(no_swap, last_swap);
            swap = Math.min(swap, last_no_swap + 1);
        }
        last_no_swap = no_swap, last_swap = swap;
    }
    return Math.min(last_swap, last_no_swap);
};