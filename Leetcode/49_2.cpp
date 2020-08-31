/**
 * 49. 字母异位词分组
 * link：https://leetcode-cn.com/problems/group-anagrams/
 */

/**
 * Categorize by Sorted String
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int index = 0;
        unordered_map<string, int> store;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (store.find(tmp) != store.end())
            {
                result[store[tmp]].push_back(strs[i]);
            }
            else
            {
                store[tmp] = index++;
                result.push_back(move(vector<string>{strs[i]}));
            }
        }
        return result;
    }
};