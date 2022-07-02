/**
 * 556. 下一个更大元素 III
 * link：https://leetcode.cn/problems/next-greater-element-iii/
 */

/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function (n) {
    let nums = n.toString().split('');
    let size = nums.length;

    let i = size - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i < 0) {
        return -1;
    }

    let j = size - 1;
    while (j >= 0 && nums[i] >= nums[j]) {
        j--;
    }

    [nums[i], nums[j]] = [nums[j], nums[i]];
    reverse(nums, i + 1, size - 1);
    const answer = 0 + nums.join('');
    return answer >= 2 ** 31 ? -1 : answer;
};

var reverse = function (nums, begin, end) {
    let i = begin, j = end;
    while (i < j) {
        [nums[i], nums[j]] = [nums[j], nums[i]];
        i++;
        j--;
    }
}
