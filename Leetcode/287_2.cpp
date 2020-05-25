/**
 * 287. 寻找重复数 floyd cycle finding
 * link：https://leetcode-cn.com/problems/find-the-duplicate-number/
 */

/**
 * We assume that nums[i] corresponds to the next in the linked list node, 
 * then repeated nums[i] will cause the node to have a degree > 2 which means that a loop appear
 * 
 * Assuming that the cycle length is L, the number of steps from starting point to the entrance of the cycle is a, 
 * continue b steps from the entrance to the meeting position, 
 * and continue c steps from the meeting position to back to the entrance, then b + c = L
 * 
 * so slow = a + b and fast = 2 * (a + b) and fast - slow = k * L
 * a = (k - 1)L + c, (c ~ 1 * a) so this time if we let slow restart from 0 and fast continue 1 step as slow do
 * then b + a = a + K * L and they meet on the entrance
 */
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};