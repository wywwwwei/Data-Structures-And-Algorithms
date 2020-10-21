/**
 * 925. 长按键入
 * link：https://leetcode-cn.com/problems/long-pressed-name/
 */

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int n = name.length();
        int m = typed.length();
        if (m < n)
            return false;

        int i = 0;
        int j = 0;
        while (j < m)
        {
            if (i < n && name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        return i == n;
    }
};