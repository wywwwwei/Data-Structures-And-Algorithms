/**
 * 1365. 有多少小于当前数字的数字
 * link：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 */

/**
 * Method 1:
 * Sort them and record the corresponding index, then traverse
 * 1. array[i+1] > array[i]  result[index(i+1)] = i;
 * 2. array[i+1] = array[i]  result[index(i+1)] = result[index(i)]
 * 
 * Method 2:
 * use array[101] to record the number of occurrences of each value
 * and sum[101] to record the number of values smaller than each value
 * sum[i] = sum[i-1] + array[i-1]
 */

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> tmp(n);
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            tmp[i].first = nums[i];
            tmp[i].second = i;
        }

        sort(tmp.begin(), tmp.end());

        result[tmp[0].second] = 0;
        for (int i = 1; i < n; i++)
        {
            if (tmp[i].first > tmp[i - 1].first)
                result[tmp[i].second] = i;
            else
                result[tmp[i].second] = result[tmp[i - 1].second];
        }

        return result;
    }
};