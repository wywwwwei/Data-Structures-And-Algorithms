/**
 * 565. 数组嵌套
 * link：https://leetcode.cn/problems/array-nesting/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayNesting = function (nums) {
    const n = nums.length;
    let answer = 0;
    for (let i = 0; i < n; i++) {
        let count = 0;
        while (nums[i] < n) {
            const num = nums[i];
            nums[i] = n;
            i = num;
            count++;
        }
        answer = Math.max(answer, count);
    }
    return answer;
};