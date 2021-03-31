/**
 * 1006. 笨阶乘
 * link：https://leetcode-cn.com/problems/clumsy-factorial/
 */

class Solution
{
public:
    int clumsy(int N)
    {
        vector<int> stk;
        stk.emplace_back(N);

        --N;
        int count = 0;
        while (N > 0)
        {
            switch (count % 4)
            {
            case 0:
                stk.back() *= N;
                break;
            case 1:
                stk.back() /= N;
                break;
            case 2:
                stk.back() += N;
                break;
            case 3:
                stk.emplace_back(-N);
                break;
            }
            ++count;
            --N;
        }

        return accumulate(stk.begin(), stk.end(), 0);
    }
};