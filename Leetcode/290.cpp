/**
 * 290. 单词规律
 * link：https://leetcode-cn.com/problems/word-pattern/
 */

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;

        int m = pattern.length(), n = s.length();
        int index = 0;
        for (const char &c : pattern)
        {
            if (index > n)
                return false;

            int ending = index;
            while (ending < n && s[ending] != ' ')
                ending++;

            string cur = s.substr(index, ending - index);
            if (p2s.find(c) != p2s.end() && cur.compare(p2s[c]) != 0)
                return false;
            if (s2p.find(cur) != s2p.end() && c != s2p[cur])
                return false;
            p2s[c] = cur;
            s2p[cur] = c;
            index = ending + 1;
        }
        return index >= n;
    }
};