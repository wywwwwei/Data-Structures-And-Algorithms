/**
 * 面试题 01.08. 零矩阵
 * link：https://leetcode-cn.com/problems/zero-matrix-lcci/
 */

/**
 * By setting the values stored in the first row and the first column to 0, 
 * the corresponding rows and columns need to be cleared to zero.
 * 
 * But [0][0] is special because it represents both row 0 and column 0, 
 * so you need to set a bool value to distinguish
 */

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool row_select = false;
        bool col_select = false;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        row_select = true;
                    if (j == 0)
                        col_select = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < matrix.size(); i++)
                    matrix[i][j] = 0;
            }
        }

        if (row_select)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        if (col_select)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};