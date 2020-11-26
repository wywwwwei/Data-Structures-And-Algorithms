/**
 * 454. 四数相加 II
 * link：https://leetcode-cn.com/problems/4sum-ii/
 */

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> sumAB;

        for (const int &a : A)
            for (const int &b : B)
                sumAB[a + b]++;

        int result = 0;
        for (const int &c : C)
            for (const int &d : D)
                if (sumAB.find(-c - d) != sumAB.end())
                    result += sumAB[-c - d];

        return result;
    }
};