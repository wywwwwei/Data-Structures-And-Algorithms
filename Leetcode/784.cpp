/**
 * 784. 字母大小写全排列
 * link：https://leetcode.cn/problems/letter-case-permutation/
 */

class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> result;
        vector<char> current(s.size(), 0);
        dfs(result, current, s, 0);
        return result;
    }

    void dfs(vector<string> &result, vector<char> &current, const string &src, int index)
    {
        while (index < src.size() && !isalpha(src[index]))
        {
            current[index] = src[index];
            index++;
        }
        if (index >= src.size())
        {
            result.emplace_back(current.begin(), current.end());
            return;
        }
        current[index] = tolower(src[index]);
        dfs(result, current, src, index + 1);

        current[index] = toupper(src[index]);
        dfs(result, current, src, index + 1);
    }
};