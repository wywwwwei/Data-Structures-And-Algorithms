/**
 * 870. 优势洗牌
 * link：https://leetcode.cn/problems/advantage-shuffle/
 */

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var advantageCount = function (nums1, nums2) {
    const n = nums1.length;
    const nums1Index = new Array(n).fill(0).map((_, index) => index);
    const nums2Index = [...nums1Index];
    nums1Index.sort((a, b) => (nums1[a] - nums1[b]));
    nums2Index.sort((a, b) => (nums2[a] - nums2[b]));

    const result = new Array(n).fill(0);
    let left = 0, right = n - 1;
    for (let i = 0; i < n; i++) {
        const num1 = nums1[nums1Index[i]];
        const num2 = nums2[nums2Index[left]];
        if (num1 > num2) {
            result[nums2Index[left]] = num1;
            left++;
        } else {
            result[nums2Index[right]] = num1;
            right--;
        }
    }

    return result;
};