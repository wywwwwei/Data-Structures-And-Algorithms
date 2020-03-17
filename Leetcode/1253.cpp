/**
 * 1253. 重构 2 行二进制矩阵 贪心
 * link：https://leetcode-cn.com/problems/add-two-numbers/
 */

class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        int check_sum = 0;
        int min_sum = 0;
        for (int sum : colsum)
        {
            check_sum += sum;
            if (sum == 2)
                min_sum++;
        }
        if (min_sum > upper || min_sum > lower || check_sum != upper + lower)
            return {};

        vector<vector<int>> result(2, vector<int>(colsum.size(), 0));
        int i = 0;
        for (int sum : colsum)
        {
            if (sum == 0)
                result[0][i] = 0, result[1][i] = 0;
            else if (sum == 1)
            {
                if (upper > lower)
                    result[0][i] = 1, result[1][i] = 0, upper--;
                else
                    result[0][i] = 0, result[1][i] = 1, lower--;
            }
            else
            {
                result[0][i] = 1, result[1][i] = 1, upper--, lower--;
            }
            i++;
        }
        return result;
    }
};