/**
 * 202. 快乐数 快慢指针
 * link：https://leetcode-cn.com/problems/happy-number/
 */

class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = getBitSum(n);
        while (fast != 1 && fast != slow)
        {
            slow = getBitSum(slow);
            fast = getBitSum(getBitSum(fast));
        }
        return fast == 1;
    }

    int getBitSum(int x)
    {
        int result = 0;
        int remain = 0;
        while (x > 0)
        {
            remain = x % 10;
            result += remain * remain;
            x /= 10;
        }
        return result;
    }
};