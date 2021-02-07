/**
 * 665. 非递减数列
 * link：https://leetcode-cn.com/problems/non-decreasing-array/
 */

/**
 * For an increasing sequence where nums[i] <= nums[i + 1], if we change one of them,
 * 1. modify the first or last value      
 *    /       /\
 *  \/   or  /
 * 2. modify the value elsewhere
 *
 *        /
 *    /  /
 *   /
 * so if an array does not match one of the three conditions mentioned above, it return false
 * step 1. Find the left half and the right half increment sequence (for condition 1, at least one of them has a length of 1)
 * step 2.1. If there is any values between the two increasing sequences, return false
 *           because  right half < these(>=1) values < left half, 
 *           we need to change these values + the endpoint of the left/right half > 2
 * step 2.2  If there is any values between the two increasing sequences
 *           we need to make sure after modifying, nums[left-1] <= nums[left] <= nums[right] <= nums[right+1]
 *           so before modifying, it can be nums[left-1] <= nums[left] > nums[right] <= nums[right+1]
 *           1. old nums[left] -> [nums[left-1], nums[right]]   -> nums[left-1] <= nums[right]
 *           2. old nums[right] -> [nums[left],nums[right+1]]   -> nums[left] <= nums[right+1]
 */

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();

        // left to right
        int left = 0;
        while (left < n - 1 && nums[left] <= nums[left + 1])
            ++left;

        if (left == n - 1)
            return true;

        // right to left
        int right = n - 1;
        while (right >= left && nums[right] >= nums[right - 1])
            --right;

        if (right - left > 1)
            return false;
        if (left == 0 || right == n - 1)
            return true;
        if (nums[left] <= nums[right + 1] || nums[right] >= nums[left - 1])
            return true;
        return false;
    }
};