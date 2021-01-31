/**
 * 888. 公平的糖果棒交换
 * link：https://leetcode-cn.com/problems/fair-candy-swap/
 */

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);

        // trades decreased space usage with increased time
        // for (int a : A)
        // {
        //     for (int b : B)
        //     {
        //         int diff = a - b;
        //         if (sumA - diff == sumB + diff)
        //             return {a, b};
        //     }
        // }

        int diff = (sumA - sumB) / 2;
        unordered_set<int> sugarA(A.begin(), A.end());

        for (auto b : B)
        {
            int need = b + diff;
            if (sugarA.find(need) != sugarA.end())
                return {need, b};
        }

        return {-1, -1};
    }
};