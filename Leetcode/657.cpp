/**
 * 657. 机器人能否返回原点 模拟
 * link：https://leetcode-cn.com/problems/robot-return-to-origin/
 */

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;
        for (const auto &move : moves)
        {
            switch (move)
            {
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'L':
                x -= 1;
                break;
            case 'R':
                x += 1;
                break;
            default:
                break;
            }
        }
        return x == 0 && y == 0;
    }
};