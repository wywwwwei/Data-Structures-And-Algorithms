/**
 * 529. Minesweeper
 * link：https://leetcode.com/problems/minesweeper/
 */

class Solution
{
    static constexpr int move[8][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else
            dfs(board, click[0], click[1]);
        return board;
    }

    void dfs(vector<vector<char>> &board, int x, int y)
    {
        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            int dx = x + move[i][0];
            int dy = y + move[i][1];
            if (dx < 0 || dx >= board.size() || dy < 0 || dy >= board[0].size())
                continue;
            count += (board[dx][dy] == 'M');
        }

        if (count > 0)
            board[x][y] = '0' + count;
        else
        {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i++)
            {
                int dx = x + move[i][0];
                int dy = y + move[i][1];
                if (dx < 0 || dx >= board.size() || dy < 0 || dy >= board[0].size() || board[dx][dy] != 'E')
                    continue;
                dfs(board, dx, dy);
            }
        }
    }
};