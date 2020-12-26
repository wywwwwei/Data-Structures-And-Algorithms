/**
 * 85. 最大矩形
 * link：https://leetcode-cn.com/problems/maximal-rectangle/
 */

/**
 * reference:
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 */
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m <= 0)
            return 0;
        int n = matrix[0].size();

        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1')
                    left[i][j] = (j > 0 ? left[i][j - 1] + 1 : 1);

        int result = 0;
        for (int j = 0; j < n; j++)
        {
            vector<int> up(m), down(m, m);
            stack<int> minWidth;

            for (int i = 0; i < m; i++)
            {
                while (!minWidth.empty() && left[minWidth.top()][j] >= left[i][j])
                {
                    down[minWidth.top()] = i;
                    minWidth.pop();
                }
                up[i] = (minWidth.empty() ? -1 : minWidth.top());
                minWidth.push(i);
            }

            for (int i = 0; i < m; i++)
                result = max(result, left[i][j] * (down[i] - up[i] - 1));
        }
        return result;
    }
};