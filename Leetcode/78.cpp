/**
 * 78. 子集 Cascading
 * link：https://leetcode-cn.com/problems/subsets/
 */

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        result.push_back(vector<int>());

        for (const auto &num : nums)
        {
            int size = result.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> cur(result[i]);
                cur.push_back(num);
                result.push_back(cur);
            }
        }
        return result;
    }
};