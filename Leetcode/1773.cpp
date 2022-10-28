/**
 * 1773. 统计匹配检索规则的物品数量
 * link：https://leetcode.cn/problems/count-items-matching-a-rule/
 */

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int index = indexOfRuleKey(ruleKey);
        if (index < 0)
        {
            return 0;
        }

        int result = 0;
        for (const auto &item : items)
        {
            if (item[index] == ruleValue)
            {
                result++;
            }
        }
        return result;
    }

    int indexOfRuleKey(const string &ruleKey)
    {
        std::unordered_map<std::string, int> indexMap{{"type", 0}, {"color", 1}, {"name", 2}};
        if (indexMap.find(ruleKey) != indexMap.end())
        {
            return indexMap[ruleKey];
        }
        return -1;
    }
};