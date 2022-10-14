/**
 * 1441. 用栈操作构建数组
 * link：https://leetcode.cn/problems/build-an-array-with-stack-operations/
 */

/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function (target, n) {
    let result = [];

    let prev = 1;
    for (const num of target) {
        for (let i = prev; i < num; i++) {
            result.push("Push");
            result.push("Pop");
        }
        result.push("Push");
        prev = num;
    }

    return result;
};