/**
 * 978. 最长湍流子数组
 * link：https://leetcode-cn.com/problems/longest-turbulent-subarray/
 */

/**
 * Condition 1 : A / B \ C or A \ B / C     ->  r++
 * Condition 2 : A / B / C or A \ B \ C     ->  l = r points to B
 * Condition 3 : A / B = C or A \ B = C     ->  l = ++r points to C
 * 
 * Use variable last to record Compare(A,B) and variable cur to record Compare(B,C)
 */

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &A)
    {
        int n = A.size();
        if (n == 1)
            return 1;

        int l = 0;
        int r = 0;
        int result = 1;
        bool cur;
        bool last;

        while (r < n - 1)
        {
            cur = (A[r] > A[r + 1]);
            if (l == r)
                last = !cur;

            if (A[r] == A[r + 1])
            {
                l = ++r;
            }
            else if (last != cur)
            {
                result = max(result, r - l + 2);
                last = cur;
                r++;
            }
            else
            {
                l = r;
            }
        }

        return result;
    }
};