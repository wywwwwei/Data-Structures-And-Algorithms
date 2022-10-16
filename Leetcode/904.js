/**
 * 904. 水果成篮
 * link：https://leetcode.cn/problems/fruit-into-baskets/
 */

/**
 * @param {number[]} fruits
 * @return {number}
 */
var totalFruit = function (fruits) {
    const n = fruits.length;

    let result = 0;
    let left = 0, right = 0;
    const count = new Map();
    while (right < n) {
        const fruit = fruits[right];
        count.set(fruit, count.has(fruit) ? count.get(fruit) + 1 : 1);
        while (count.size > 2) {
            const deleteFruit = fruits[left];
            const deleteCount = count.get(deleteFruit);
            if (deleteCount === 1) {
                count.delete(deleteFruit);
            } else {
                count.set(deleteFruit, deleteCount - 1);
            }
            left++;
        }
        result = Math.max(result, right - left + 1);
        right++;
    }
    return result;
};