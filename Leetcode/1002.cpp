/**
 * 1002. 查找常用字符
 * link：https://leetcode-cn.com/problems/find-common-characters/
 */

const int alpha_size = 26;

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<int> total_count(alpha_size, INT_MAX);
        vector<int> cur_count(alpha_size, 0);

        for (const string &a : A)
        {
            fill(cur_count.begin(), cur_count.end(), 0);
            for (const char &c : a)
                cur_count[c - 'a']++;
            for (int i = 0; i < alpha_size; i++)
                total_count[i] = min(total_count[i], cur_count[i]);
        }

        vector<string> result;
        for (int i = 0; i < alpha_size; i++)
            for (int j = 0; j < total_count[i]; j++)
                result.emplace_back(1, 'a' + i);
        return result;
    }
};