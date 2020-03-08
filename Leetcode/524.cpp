/**
 * 524. 通过删除字母匹配到字典里最长单词 双指针逐个比较是否匹配，同时选出最长、字典序最小的字符串
 * link：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
 */

class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        int s_len = s.length();
        int d_len = d.size();
        int res_index = -1;
        for (int i = 0; i < d_len; i++)
        {
            int index1 = 0, index2 = 0;
            int dic_len = d[i].length();
            while (index1 < s_len && index2 < dic_len)
            {
                if (s[index1] == d[i][index2])
                    index1++, index2++;
                else
                    index1++;
            }
            if (index2 == dic_len)
            {
                if (res_index == -1 || d[res_index].length() < d[i].length() || (d[res_index].length() == d[i].length() && d[res_index] > d[i]))
                    res_index = i;
            }
        }
        return res_index == -1 ? "" : d[res_index];
    }
};