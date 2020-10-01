/**
 * 771. 宝石与石头
 * link：https://leetcode-cn.com/problems/jewels-and-stones/
 */

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        bool jewel_lower[26] = {false};
        bool jewel_upper[26] = {false};
        for (const char &j : J)
        {
            if (j <= 'Z')
                jewel_upper[j - 'A'] = true;
            else
                jewel_lower[j - 'a'] = true;
        }
        int result = 0;
        for (const char &s : S)
        {
            if (s <= 'Z')
                result += (jewel_upper[s - 'A'] ? 1 : 0);
            else
                result += (jewel_lower[s - 'a'] ? 1 : 0);
        }
        return result;
    }
};