/**
 * 1047. 删除字符串中的所有相邻重复项   parentheses matching
 * link：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 */

class Solution
{
public:
    string removeDuplicates(string S)
    {
        int n = S.length();

        string st;
        for (const char c : S)
        {
            if (!st.empty() && c == st.back())
                st.pop_back();
            else
                st.push_back(c);
        }

        return st;
    }
};