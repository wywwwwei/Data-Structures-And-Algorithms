/**
 * 481. 神奇字符串
 * link：https://leetcode.cn/problems/magical-string/
 */

class Solution
{
public:
    int magicalString(int n)
    {
        vector<int> stack;
        int current = 0, result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (stack.size() > i ? stack[i] : 1); j++)
            {
                stack.push_back(i % 2 == 0 ? 1 : 2);
            }
            if (i % 2 == 0)
            {
                result += min(stack[i], n - current);
            }
            current += stack[i];
            if (current >= n)
            {
                break;
            }
        }
        return result;
    }
};