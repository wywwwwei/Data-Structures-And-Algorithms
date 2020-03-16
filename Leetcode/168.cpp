/**
 * 168. Excel表列名称
 * link：https://leetcode-cn.com/problems/excel-sheet-column-title/
 */

/**
 *  A -> Z   : 26 * '0' + '1' -> 26 * '0' + '26'
 *  AA -> AZ : 26 * '1' + '1' -> 26 * '1' + '26'   ZA -> ZZ : 26 * '26' + '1' -> 26 * '26' + '26'
 *  AAA -> AAZ : 26 * (26 * '1' + '1') + '1' -> 26 * (26 * '1' + '1') + '26'
 *  We can find that 
 *  each duration can be present as (26 * x) + 1 -> (26 * x) + 26 ;
 *  So x = (n - 1) / 26
 *  
 */
class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";

        for (int i = n; i > 0; i = (i - 1) / 26)
        {
            res += char('A' + (i - 1) % 26);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};