/**
 * 面试题 17.19. 消失的两个数字
 * link：https://leetcode.cn/problems/missing-two-lcci/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var missingTwo = function (nums) {
    const n = nums.length;
    const targetN = n + 2;

    let targetXOR = 0;
    for (let i = 1; i <= targetN; ++i) {
        targetXOR ^= i;
    }
    const diff = nums.reduce((prev, cur) => (prev ^ cur), targetXOR);

    const lowBit = diff & (-diff);
    let lowBitXOR = 0;
    for (let i = 1; i <= targetN; ++i) {
        if (i & lowBit) {
            lowBitXOR ^= i;
        }
    }
    lowBitXOR = nums.reduce((prev, cur) => (cur & lowBit ? prev ^ cur : prev), lowBitXOR);

    return [lowBitXOR, diff ^ lowBitXOR]
};