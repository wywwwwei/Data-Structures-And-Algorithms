/**
 * [编程题]vivo智能手机产能
 * https://www.nowcoder.com/questionTerminal/2e4363c23c6741f98319d5a7e3882325
 */

class Solution {
public:
    /**
     * 
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
        int result = 0;

        int i = 1;
        while(n >= i)
        {
            result += i * i;
            n -= i;
            ++i;
        }
        result += n * i;

        return result;
    }
};

int main()
{
    cout << Solution().solution(11) << endl;
}