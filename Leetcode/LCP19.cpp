/**
 * LCP 19. 秋叶收藏集 DP
 * link：https://leetcode-cn.com/problems/UlBDOe/
 */

/**
 * There are three states in each position:
 *      [Red Yellow Red]
 * State  1     2    3
 * 
 * State transition
 * State 1 + 'r' -> State 1
 * State 1 + 'y' -> State 2
 * State 2 + 'r' -> State 3
 * State 2 + 'y' -> State 2
 * State 3 + 'r' -> State 3
 */

class Solution
{
public:
    int minimumOperations(string leaves)
    {
        int n = leaves.length();

        int r_turn = (leaves[0] == 'y' ? 1 : 0);
        int y_turn = INT_MAX - 1;
        int end_turn = INT_MAX - 1;
        for (int i = 1; i < n; i++)
        {
            if (leaves[i] == 'r')
            {
                end_turn = min(end_turn, y_turn);
                y_turn = min(r_turn, y_turn) + 1;
            }
            else
            {
                end_turn = min(end_turn, y_turn) + 1;
                y_turn = min(r_turn, y_turn);
                r_turn = r_turn + 1;
            }
        }

        return end_turn;
    }
};