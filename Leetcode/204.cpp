/**
 * 204. 计数质数    The Sieve of Eratosthenes
 * link：https://leetcode-cn.com/problems/count-primes/
 */

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        int result = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                result++;
                if ((long long)i * i < n)
                {
                    for (int j = i * i; j < n; j += i)
                        isPrime[j] = false;
                }
            }
        }
        return result;
    }
};