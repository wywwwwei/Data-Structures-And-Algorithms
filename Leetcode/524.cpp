/**
 * 524. 通过删除字母匹配到字典里最长单词 双指针逐个比较后，输出最长、字典序最小的字符串
 * link：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
 */

class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        vector<int> res_index;
        int s_len = s.length();
        int d_len = d.size();
        //Select the matching string index
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
                res_index.push_back(i);
        }
        if (res_index.empty())
        {
            return "";
        }
        //Pick the most suitable value
        int res_len = res_index.size();
        int max = res_index[0];
        for (int i = 1; i < res_len; i++)
        {
            if (d[res_index[i]].length() > d[max].length())
            {
                max = res_index[i];
            }
            else if (d[res_index[i]].length() == d[max].length() && d[res_index[i]] < d[max])
            {
                max = res_index[i];
            }
        }
        return d[max];
    }
};