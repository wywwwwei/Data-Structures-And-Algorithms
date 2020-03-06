/**
 * 167. 两数之和 II - 输入有序数组 双指针
 * link：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        while (index1 < index2)
        {
            /**
             * Consider the addition of two integers may overflow
             * e.g.
             * numbers = [1,7,11,2147483647]
             * target = 12
             */
            long sum = (long)numbers[index1] + (long)numbers[index2];
            if (sum < target)
            {
                index1++;
            }
            else if (sum > target)
            {
                index2--;
            }
            else
            {
                return {index1 + 1, index2 + 1};
            }
        }
        return {index1 + 1, index2 + 1};
    }
};
