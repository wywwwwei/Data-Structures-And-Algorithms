/**
 * 27. 移除元素
 * link：https://leetcode-cn.com/problems/remove-element/
 */

/**
 * This question is the same as Question 26.
 * 
 * The key point is to overwrite the value that needs to be deleted 
 * with the value that does not need to be deleted.
 */

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int index = nums.size();

        for (int i = 0; i < index;)
        {
            if (nums[i] == val)
            {
                index--;
                nums[i] = nums[index];
            }
            else
                i++;
        }

        return index;
    }
};