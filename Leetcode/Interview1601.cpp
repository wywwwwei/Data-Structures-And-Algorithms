/**
 * 面试题 16.01. 交换数字
 * link：https://leetcode-cn.com/problems/swap-numbers-lcci/
 */

class Solution
{
public:
    vector<int> swapNumbers(vector<int> &numbers)
    {
        // There is a risk of integer overflow in addition
        // a = a + b;
        // b = a - b;
        // a = a - b;
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;

        //interesting solution
        //return {numbers[1],numbers[0]};
    }
};