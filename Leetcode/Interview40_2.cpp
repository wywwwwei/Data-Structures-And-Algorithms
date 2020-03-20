/**
 * 面试题40. 最小的k个数 先排序后选取
 * link：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 */

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        vector<int> result(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++)
            result[i] = arr[i];
        return result;
    }
};