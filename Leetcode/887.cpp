/**
 * 887. 鸡蛋掉落 dp + 决策单调性
 * link：https://leetcode-cn.com/problems/super-egg-drop/
 */

class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        vector<int> dp_k_1(N + 1, 0);
        for (int i = 0; i <= N; i++)
            dp_k_1[i] = i;

        for (int i = 1; i < K; i++)
        {
            vector<int> dp_k(N + 1, 0);
            int x = 1;
            for (int n = 1; n <= N; n++)
            {
                while (x < n && max(dp_k_1[x - 1], dp_k[n - x]) >= max(dp_k_1[x], dp_k[n - x - 1]))
                    x++;
                dp_k[n] = 1 + max(dp_k_1[x - 1], dp_k[n - x]);
            }
            for (int n = 1; n <= N; ++n)
                dp_k_1[n] = dp_k[n];
        }

        return dp_k_1[N];
    }
};