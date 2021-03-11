/**
 * 331. 验证二叉树的前序序列化
 * link：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
 */

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int n = preorder.length();

        int slots = 1;
        int i = 0;
        while (i < n)
        {
            if (slots == 0)
                return false;

            if (preorder[i] == '#')
            {
                --slots;
                ++i; // eat '#'
            }
            else
            {
                while (i < n && preorder[i] != ',')
                    ++i;
                slots += 1; // slots = slots - 1 + 2
            }
            ++i; // skip ','
        }

        return slots == 0;
    }
};