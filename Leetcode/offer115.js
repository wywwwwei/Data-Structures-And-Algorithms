/**
 * 剑指 Offer II 115. 重建序列
 * link：https://leetcode.cn/problems/ur2n8P/
 */

// To verify nums is a unique shortest sequence that all subsequences are subsequences of.
// According to the question
// 1. All sequences are subsequences of nums.
// 2. Nums is a permutations from 1 to n
// => Consider all subsequences are constructed into a graph, if there is topological sort, the result is unique.

// So we need to
// 1. Check if it is the shortest => No nodes other than sequences appear in nums
// 2. Check if it is unique 
// => Check the result of topological sort exists

/**
 * @param {number[]} nums
 * @param {number[][]} sequences
 * @return {boolean}
 */
var sequenceReconstruction = function (nums, sequences) {
    const n = nums.length;
    const graph = Array(n + 1).fill(null).map(() => new Set());
    for (const sequence of sequences) {
        const len = sequence.length;
        for (let i = 1; i < len; i++) {
            graph[sequence[i - 1]].add(sequence[i]);
        }
    }
    for (let i = 1; i < n; i++) {
        if (!graph[nums[i - 1]].has(nums[i])) {
            return false;
        }
    }
    return true;
};