/**
 * 49. 字母异位词分组
 * link：https://leetcode-cn.com/problems/group-anagrams/
 */

/**
 * Categorize by count (custom coding)
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int index = 0;
        unordered_map<string, int> store;
        vector<vector<string>> result;
        int count[26];
        string encode;

        for (int j = 0; j < strs.size(); j++)
        {
            memset(count, 0, 26 * sizeof(int));
            encode.clear();

            for (int i = 0; i < strs[j].length(); i++)
            {
                count[(int)(strs[j][i] - 'a')]++;
            }

            for (int i = 0; i < 26; i++)
            {
                encode += '#';
                encode += to_string(count[i]);
            }

            if (store.find(encode) != store.end())
            {
                result[store[encode]].push_back(strs[j]);
            }
            else
            {
                store[encode] = index++;
                result.push_back({strs[j]});
            }
        }

        return result;
    }
};
