/**
 * 60. 第k个排列
 * link：https://leetcode-cn.com/problems/permutation-sequence/
 */

/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * Suppose we need the k-th permutation sequence. k = [0 ... n! - 1], and the list of numbers that we haven't chosen yet S = {1,2...,n}
 * The i-th (0 <= i < n) digit has (n-i) options, and when it is selected, it contains (n-i-1)! permutations.
 * So the first digit = S[ k / (n - 0 - 1)! ]
 * k = k % (n - 0 - 1)! and the second digit = S[ k / (n - 1 - 1)!]
 * .....
 * 
 * Specific explanation can refer to
 * https://leetcode-cn.com/problems/permutation-sequence/solution/di-kge-pai-lie-by-leetcode-solution/
 */

/* 
class Solution
{
    void buildFactorial(int n, int factorial[10])
    {
        factorial[0] = 1;
        for (int i = 1; i < n + 1; i++)
            factorial[i] = factorial[i - 1] * i;
    }

    int getVal(int n, bool visited[10])
    {
        int index = 1;
        while (n >= 0)
        {
            if (!visited[index])
                n--;
            index++;
        }
        visited[--index] = true;
        return index;
    }

public:
    string getPermutation(int n, int k)
    {
        int factorial[10];
        buildFactorial(n, factorial);

        string result(n, '0');
        bool visited[10] = {false};

        int val = 0;
        int count = 0;
        k--;
        while (count < n)
        {
            val = k / factorial[n - count - 1];
            k %= factorial[n - count - 1];
            result[count++] = '0' + getVal(val, visited);
        }

        return result;
    }
};
 */

// Optimized version
class Solution
{
    //Before C++17
    //static constexpr array<int, 9> factorial{1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    static constexpr array factorial{1, 1, 2, 6, 24, 120, 720, 5040, 40320};

public:
    string getPermutation(int n, int k)
    {
        vector<int> choice(n, 0);
        string result(n, '0');
        iota(choice.begin(), choice.end(), 1);

        int count = 0;
        k--;
        while (count < n)
        {
            vector<int>::iterator iter = choice.begin() + (k / factorial[n - count - 1]);
            k %= factorial[n - count - 1];
            result[count++] = '0' + *iter;
            choice.erase(iter);
        }

        return result;
    }
};

/* 
// before C++17
constexpr array<int, 9> Solution::factorial;
 */