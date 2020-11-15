/**
 * 402. 移掉K位数字
 * link：https://leetcode-cn.com/problems/remove-k-digits/
 */

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int targetLen = num.length() - k;
        if (targetLen == 0)
            return "0";

        // monotonous stack
        vector<char> store;
        for (const char &n : num)
        {
            while (!store.empty() && n < store.back() && k > 0)
            {
                store.pop_back();
                k--;
            }
            store.push_back(n);
        }

        // for non-strictly increasing sequence
        while (k-- > 0)
            store.pop_back();

        // elimate leading zero
        int idx = 0, count = 0;
        while (idx < store.size() && store[idx] == '0')
            idx++;

        string result((targetLen - idx > 0 ? targetLen - idx : 1), '0');
        while (idx < store.size())
            result[count++] = store[idx++];
        return result;
    }
};