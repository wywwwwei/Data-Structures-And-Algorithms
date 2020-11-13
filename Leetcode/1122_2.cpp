/**
 * 1122. 数组的相对排序
 * link：https://leetcode-cn.com/problems/relative-sort-array/
 */

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); i++)
            rank[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&rank](const int &a, const int &b) {
            if (rank.find(a) != rank.end())
                return (rank.find(b) != rank.end() ? rank[a] < rank[b] : true);
            else
                return (rank.find(b) != rank.end() ? false : a < b);
        });

        return arr1;
    }
};