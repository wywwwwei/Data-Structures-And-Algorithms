/**
 * 17. 电话号码的字母组合
 * link：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution
{
    unordered_map<char, string> num2char = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string cur;
    vector<string> result;

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() <= 0)
            return {};
        dfs(digits, 0);
        return result;
    }

    void dfs(string &digits, int index)
    {
        if (index == digits.length())
        {
            result.push_back(cur);
            return;
        }
        auto &match = num2char[digits[index]];
        for (const char &m : match)
        {
            cur.push_back(m);
            dfs(digits, index + 1);
            cur.pop_back();
        }
    }
};