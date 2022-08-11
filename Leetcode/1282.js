/**
 * 1282. 用户分组
 * link：https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/
 */

/**
 * @param {number[]} groupSizes
 * @return {number[][]}
 */
var groupThePeople = function (groupSizes) {
    const groups = new Map();
    const n = groupSizes.length;
    for (let i = 0; i < n; i++) {
        const groupSize = groupSizes[i];
        if (!groups.has(groupSize)) {
            groups.set(groupSize, []);
        }
        groups.get(groupSize).push(i);
    }
    let result = [];
    groups.forEach((value, key, _) => {
        for (let i = 0; i < value.length; i += key) {
            result.push(value.slice(i, i + key));
        }
    });
    return result;
};