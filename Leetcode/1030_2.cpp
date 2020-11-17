/**
 * 1030. 距离顺序排列矩阵单元格
 * link：https://leetcode-cn.com/problems/matrix-cells-in-distance-order/
 */

/**
 * BFS with space optimization
 */

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> result(R * C, vector<int>(2, 0));
        result[0][0] = r0;
        result[0][1] = c0;
        int count = 1;
        // How to move
        //          third
        // fourth   (r0,c0)    second
        //          first
        int move[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int max_dis = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        int cur_x = r0, cur_y = c0;
        for (int dis = 0; dis < max_dis; dis++)
        {
            cur_x--;
            for (int j = 0; j < 4; j++)
            {
                while ((j % 2 == 0 && cur_x != r0) || (j % 2 == 1 && cur_y != c0))
                {
                    if (cur_x >= 0 && cur_x < R && cur_y >= 0 && cur_y < C)
                        result[count][0] = cur_x, result[count++][1] = cur_y;
                    cur_x += move[j][0];
                    cur_y += move[j][1];
                }
            }
        }

        return result;
    }
};