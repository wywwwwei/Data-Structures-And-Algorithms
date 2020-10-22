/**
 * 763. 划分字母区间
 * link：https://leetcode-cn.com/problems/partition-labels/
 */

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        int ending[26];

        for (int i = 0; i < S.length(); i++)
            ending[S[i] - 'a'] = i;

        vector<int> result;
        int p_start = 0, p_end = 0;
        for (int i = 0; i < S.length(); i++)
        {
            p_end = max(p_end, ending[S[i] - 'a']);
            if (i == p_end)
            {
                result.push_back(p_end - p_start + 1);
                p_start = p_end + 1;
            }
        }
        return result;
    }
};