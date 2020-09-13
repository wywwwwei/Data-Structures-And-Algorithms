/**
 * 79. 单词搜索 回溯
 * link：https://leetcode-cn.com/problems/word-search/
 */

class Solution
{
    static constexpr int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (search(board, i, j, word, 0, visited))
                        return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>> &board, int x, int y, string &word, int idx, vector<vector<bool>> &visited)
    {
        if (idx == word.length() - 1)
            return true;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + move[i][0];
            int dy = y + move[i][1];
            if (dx < 0 || dx >= board.size() || dy < 0 || dy >= board[0].size())
                continue;
            if (visited[dx][dy] || word[idx + 1] != board[dx][dy])
                continue;
            if (search(board, dx, dy, word, idx + 1, visited))
                return true;
        }
        visited[x][y] = false;
        return false;
    }
};