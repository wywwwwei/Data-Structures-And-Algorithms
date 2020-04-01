/**
 * 289. 生命游戏 额外状态
 * link：https://leetcode-cn.com/problems/game-of-life/
 */

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int move[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0;
                for (int k = 0; k < 8; k++)
                {
                    int dx = i + move[k][0];
                    int dy = j + move[k][1];
                    if (dx < 0 || dx >= m)
                        continue;
                    if (dy < 0 || dy >= n)
                        continue;
                    if (board[dx][dy] > 0)
                        count++;
                }
                if (board[i][j] == 0)
                {
                    if (count == 3)
                        board[i][j] = -1;
                    continue;
                }
                if (count < 2 || count > 3)
                    board[i][j] = 2;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == -1)
                    board[i][j] = 1;
                else if (board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};