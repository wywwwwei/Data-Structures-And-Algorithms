/**
 * 9. 回文数 翻转一半然后比较
 * link：https://leetcode-cn.com/problems/palindrome-number/
 */

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int revert = 0;

        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        while (x > revert)
        {
            revert = revert * 10 + x % 10;
            x /= 10;
        }
        return x == revert || x == revert / 10;
    }
};