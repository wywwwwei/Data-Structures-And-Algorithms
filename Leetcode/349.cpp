/**
 * 349. 两个数组的交集
 * link：https://leetcode-cn.com/problems/intersection-of-two-arrays/
 */

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        unordered_set<int> store;
        vector<int>::iterator start;
        vector<int>::iterator ending;
        if (nums1.size() > nums2.size())
        {
            store = unordered_set<int>(nums2.begin(), nums2.end());
            start = nums1.begin();
            ending = nums1.end();
        }
        else
        {
            store = unordered_set<int>(nums1.begin(), nums1.end());
            start = nums2.begin();
            ending = nums2.end();
        }

        while (start != ending)
        {
            if (store.find(*start) != store.end())
            {
                result.push_back(*start);
                store.erase(*start);
            }
            start++;
        }

        return result;
    }
};