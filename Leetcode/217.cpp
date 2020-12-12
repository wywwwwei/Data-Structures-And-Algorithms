/**
 * 217. 存在重复元素
 * link：https://leetcode-cn.com/problems/contains-duplicate/
 */

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // unordered_set<int> rec;
        // for (const int &num : nums)
        // {
        //     if (rec.find(num) != rec.end())
        //         return true;
        //     rec.insert(num);
        // }
        // return false;

        // sort(nums.begin(), nums.end());
        // return (nums.size() != (unique(nums.begin(), nums.end()) - nums.begin()));

        // return set(nums.begin(),nums.end()).size() != nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};