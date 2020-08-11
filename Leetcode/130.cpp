/**
 * 130. 被围绕的区域
 * link：https://leetcode-cn.com/problems/surrounded-regions/
 */

/**
 * As can be seen from the question:
 * Any 'O' on the border of the board are not flipped to 'X'
 * which means that we need to find all 'O' that are connected to the 'O' at the boundary,
 * then the rest of the 'O' is surrounded
 */
class Solution
{
    int m;
    int n;

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int x, int y)
    {
        if (x >= m || x < 0 || y >= n || y < 0)
            return;
        if (board[x][y] != 'O')
            return;
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};