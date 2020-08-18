/**
 * 647. 回文子串
 * link：https://leetcode-cn.com/problems/palindromic-substrings/
 */

/**
 * Manacher's Algorithm
 */
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        string newInput(2 * n + 3, '#');
        addBoundary(s, newInput);

        n = 2 * n + 1;
        vector<int> radius(n);
        int result = 0;
        int maxRadius = 0, maxMiddle = 0;
        for (int i = 2; i < n; i++)
        {
            radius[i] = (i <= maxRadius) ? min(radius[2 * maxMiddle - i], maxRadius - i + 1) : 1;
            while (newInput[i + radius[i]] == newInput[i - radius[i]])
                radius[i]++;
            if (maxRadius < i + radius[i] - 1)
            {
                maxMiddle = i;
                maxRadius = i + radius[i] - 1;
            }
            result += radius[i] / 2;
        }

        return result;
    }

    void addBoundary(string &input, string &newInput)
    {
        newInput[0] = '$';
        for (int i = 0; i < input.length(); i++)
            newInput[2 * i + 2] = input[i];
        newInput[newInput.length() - 1] = '!';
    }
};