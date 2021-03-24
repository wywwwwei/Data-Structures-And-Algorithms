/**
 * 456. 132模式
 * link：https://leetcode-cn.com/problems/132-pattern/
 */

/**
 * It is hard to find 2 even if we find possible 1 and 3, because (1,3) is not the only certainties.
 * 
 * So we use 2 and 3 to find 1, as long as we find 2,3 as large as possible
 * Use a stack to keep track of the second largeset number (2), and make sure index(largest) < index(second largest) 
 */

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;

        vector<int> stk;
        stk.emplace_back(nums[n - 1]);
        int secondLargest = INT_MIN;

        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < secondLargest)
                return true;

            while (!stk.empty() && nums[i] > stk.back())
            {
                secondLargest = stk.back();
                stk.pop_back();
            }

            if (nums[i] > secondLargest)
                stk.push_back(nums[i]);
        }

        return false;
    }
};