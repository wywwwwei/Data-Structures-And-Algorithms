/**
 * 753. 破解保险箱 Hierholzer's Algorithm
 * link：https://leetcode-cn.com/problems/cracking-the-safe/
 */

/**
 * The problem is to find the shortest string that contains all the passwords.
 * E.g. when n = 2 and k = 2, the answer could be 00/01/10/11 and the shortest combination of them is 001011, because
 *                      
 *          0 = 00      ----1--->      01   ----1--->   11 = 1
 *               A                     |A                |
 *               |                     ||                |
 *               |                     01                |
 *               |                     ||                |
 *               |                     V|                |
 *                      -----0----     10   <----0----   
 * all we have to do is find the Eulerian path (password as the edge, n-1 bits as the node)
 * e.g.     0  ----01---->  1           1234 ----12345----> 2345
 */                                     

class Solution
{
    bool visit[(int)1E5] = {false}; //you can use a hash table (unordered_set) instead
    int k;
    int top_digit = 1;
    string result;

public:
    string crackSafe(int n, int k)
    {
        //A special case: When n = 1, there is only one node.
        if (n == 1)
        {
            for (int i = k - 1; i >= 0; i--)
                result += (char)('0' + i);
            return result;
        }

        for (int i = 0; i < n - 1; i++)
            top_digit *= 10;
        this->k = k;
        string init_str(n - 1, '0');

        dfs(init_str, 0);
        return result + init_str;
    }

    void dfs(string &cur, int num)
    {
        string tmp = cur.substr(1);
        int discard = top_digit * (cur[0] - '0');
        num *= 10;

        for (int i = 0; i < k; i++)
        {
            int cur_num = num + i;
            if (!visit[cur_num])
            {
                visit[cur_num] = true;
                string cur_str = tmp + (char)('0' + i);
                dfs(cur_str, cur_num - discard);
                result += '0' + i;
            }
        }
    }
};