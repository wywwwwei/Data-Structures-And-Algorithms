/**
 * 738. 单调递增的数字
 * link：https://leetcode-cn.com/problems/monotone-increasing-digits/
 */

class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        string store = to_string(N);
        int pos = 1;
        int n = store.length();

        while (pos < n && store[pos - 1] <= store[pos])
            pos++;

        if (pos < n)
        {
            while (pos > 0 && store[pos - 1] > store[pos])
                store[--pos]--;
            while (++pos < n)
                store[pos] = '9';
        }

        return stoi(store);
    }
};