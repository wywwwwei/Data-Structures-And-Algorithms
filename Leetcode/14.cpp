/**
 * 14. 最长公共前缀
 * link：https://leetcode-cn.com/problems/longest-common-prefix/
 */

/**
 * Method 1 : LCP(str0, str1, ...) = LCP(LCP(LCP(str0, str1),str2),...)
 * Method 2 : Trie
 * Method 3 : Vertical scan : compare (str0[index] == str1[index] == str2[index] ...)
 * The following ways that I didn't come up with are referring to leetcode solution
 * Method 4 : Divide and conquer LCP(str0, str1, ...) = LCP(LCP(str0,str1), LCP(str2,str3)) ...
 * Method 5 : Binary Search
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() <= 0)
            return "";
        int index = 0;

        while (index < strs[0].length())
        {
            char index_char = strs[0][index];
            for (int i = 1; i < strs.size(); i++)
            {
                if (index >= strs[i].length())
                    return strs[0].substr(0, index);
                if (strs[i][index] != index_char)
                    return strs[0].substr(0, index);
            }
            index++;
        }

        return strs[0].substr(0, index);
    }
};