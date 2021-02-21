/**
 * 766. 托普利茨矩阵
 * link：https://leetcode-cn.com/problems/toeplitz-matrix/
 */

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                for (int z = i + 1; z < n; z++)
                {
                    if (matrix[j][z] != matrix[j - 1][z - 1])
                        return false;
                }
            }
        }
        return true;
    }
};