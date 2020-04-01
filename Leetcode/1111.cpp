/**
 * 1111. 有效括号的嵌套深度
 * link：https://leetcode-cn.com/problems/add-two-numbers/
 */

/**
 * Make max (depth (A), depth (B)) the smallest,
 * that is, make them the closest, 
 * so you only need to assign the parity depth brackets to A and B respectively.
 */
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int depth = 0;
        int index = 0;
        vector<int> result(seq.length(), 0);

        for (const char &c : seq)
        {
            if (c == '(')
            {
                depth++;
                result[index++] = depth % 2;
            }
            else
            {
                result[index++] = depth % 2;
                depth--;
            }
        }

        return result;
    }
};