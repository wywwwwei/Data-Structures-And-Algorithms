/**
 * 1773. 统计匹配检索规则的物品数量
 * link：https://leetcode.cn/problems/count-items-matching-a-rule/
 */

/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
var countMatches = function (items, ruleKey, ruleValue) {
    const index = itemIndexForRuleKey(ruleKey);
    if (index < 0) {
        return 0;
    }

    let result = 0;
    for (const item of items) {
        if (item[index] === ruleValue) {
            result++;
        }
    }
    return result;
};

const itemIndexForRuleKey = function (ruleKey) {
    if (ruleKey === "type") {
        return 0;
    } else if (ruleKey === "color") {
        return 1;
    } else if (ruleKey === "name") {
        return 2;
    }
    return -1;
}