/**
 * 999. 车的可用捕获量
 * link：https://leetcode-cn.com/problems/available-captures-for-rook/
 */

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int result = 0;
        int row = 0, col = 0;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == 'R')
                {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < 4; i++)
        {
            int drow = row + move[i][0];
            int dcol = col + move[i][1];
            while (true)
            {
                if (drow < 0 || drow >= board.size() || dcol < 0 || dcol >= board.size())
                    break;
                if (board[drow][dcol] == 'B')
                    break;
                else if (board[drow][dcol] == 'p')
                {
                    result++;
                    break;
                }
                drow = drow + move[i][0];
                dcol = dcol + move[i][1];
            }
        }

        return result;
    }
};