/**
 * [编程题]数位之积
 * https://www.nowcoder.com/questionTerminal/f9b86bcd95a643138f9593966a5495b8
 */

class Solution
{
public:
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */

    int solution(int n)
    {
        // input: n > 9

        int result = 0;
        int base = 1;

        for (int i = 9; i > 1; --i)
        {
            while (n % i == 0)
            {
                result += i * base;
                base *= 10;
                n /= i;
            }
        }

        return (n > 1 ? -1 : result);
    }
};