/**
 * 1122. 数组的相对排序
 * link：https://leetcode-cn.com/problems/relative-sort-array/
 */

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int count[1001];
        fill(count, count + 1001, 0);
        for (const int &arr : arr1)
            count[arr]++;

        vector<int> result(arr1.size());
        int pos = 0;
        for (const int &arr : arr2)
        {
            for (int i = 0; i < count[arr]; i++)
                result[pos++] = arr;
            count[arr] = 0;
        }

        for (int i = 0; i < 1001; i++)
        {
            while (count[i] > 0)
            {
                result[pos++] = i;
                count[i]--;
            }
        }
        return result;
    }
};