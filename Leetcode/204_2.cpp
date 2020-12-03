/**
 * 204. 计数质数    Euler's sieve
 * link：https://leetcode-cn.com/problems/count-primes/
 */

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> prime;
        vector<bool> isPrime(n, true);
        
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
                prime.push_back(i);
            for (int j = 0; j < prime.size() && prime[j] * i < n; j++)
            {
                isPrime[prime[j] * i] = false;
                if (i % prime[j] == 0)
                    break;
            }
        }
        return prime.size();
    }
};