/**
 * 861. 翻转矩阵后的得分
 * link：https://leetcode-cn.com/problems/score-after-flipping-matrix/
 */

class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        int n = A.size();
        int m = A[0].size();

        int result = n * (1 << (m - 1));
        for (int j = 1; j < m; j++)
        {
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                if (A[i][0] == 0)
                    cur += A[i][j];
                else
                    cur += 1 - A[i][j];
            }
            result += max(cur, n - cur) * (1 << (m - j - 1));
        }

        return result;
    }
};