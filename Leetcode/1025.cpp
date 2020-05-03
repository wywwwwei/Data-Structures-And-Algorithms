/**
 * 1025. 除数博弈
 * link：https://leetcode-cn.com/problems/divisor-game/
 */

/**
 * If N is an even number, its factors are 1, 2 and others, so N - x can be odd or even
 * If N is an odd number, its factors are odd numbers, so N -x can only be even
 * That means as long as the first hand is even, then the second hand must always be odd, so the first hand will not lose
 */

class Solution
{
public:
    bool divisorGame(int N)
    {
        return N % 2 == 0;
    }
};