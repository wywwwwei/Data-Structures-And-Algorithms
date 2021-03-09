/**
 * [编程题]手机屏幕解锁模式
 * https://www.nowcoder.com/questionTerminal/c552248efdbd41a18d35b7a2329f7ad8
 */

class Solution
{
public:
    /**
     * 实现方案
     * @param m int整型 最少m个键
     * @param n int整型 最多n个键
     * @return int整型
     */
    bool cur[9] = {false};
    int count = 1;
    int result = 0;
    static constexpr move[16][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}, {1, 2}, {2, 1}, {-2, 1}, {-1, 2}};
    int m;
    int n;

    void dfs(int x, int y)
    {
        if (count >= m)
            ++result;
        if (count == n)
            return;

        for (int j = 0; j < 16; ++j)
        {
            int dx = x + move[j][0];
            int dy = y + move[j][1];
            if (dx < 0 || dx >= 3 || dy < 0 || dy >= 3)
                continue;
            if (cur[dx * 3 + dy])
            {
                if (j >= 8)
                    continue;
                dx += move[j][0];
                dy += move[j][1];
                if (dx < 0 || dx >= 3 || dy < 0 || dy >= 3)
                    continue;
                if (cur[dx * 3 + dy])
                    continue;
            }
            cur[dx * 3 + dy] = true;
            ++count;
            dfs(dx, dy);
            cur[dx * 3 + dy] = false;
            --count;
        }
    }

    int solution(int m, int n)
    {
        m = (m <= 0 ? 1 : m);
        n = (n > 9 ? 9 : n);
        if (m > n)
            return 0;

        this->m = m;
        this->n = n;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                cur[i * 3 + j] = true;
                dfs(i, j);
                cur[i * 3 + j] = false;
            }
        return result;
    }
};