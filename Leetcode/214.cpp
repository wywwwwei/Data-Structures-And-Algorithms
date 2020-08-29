/**
 * 214. 最短回文串 Manacher’s Algorithm
 * link：https://leetcode-cn.com/problems/shortest-palindrome/
 */

/**
 * Find the longest palindrome prefix
 */

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.length() == 0)
            return "";

        int n = s.length();
        string newInput(2 * n + 3, '#');
        addBoundary(s, newInput);

        n = 2 * n + 1;
        vector<int> radius(n);
        int maxMiddle = 0;
        int maxRadius = 0;
        int prefixCut = 0;
        for (int i = 2; i < n; i++)
        {
            radius[i] = i <= maxRadius ? min(radius[2 * maxMiddle - i], maxRadius - i + 1) : 1;
            while (newInput[i + radius[i]] == newInput[i - radius[i]])
                radius[i]++;

            if (i + radius[i] - 1 > maxRadius)
            {
                maxRadius = radius[i] + i - 1;
                maxMiddle = i;
                if (i - radius[i] + 1 <= 2)
                {
                    int cur = maxRadius - maxMiddle + 1;
                    if (cur % 2)
                        prefixCut = max(prefixCut, 2 * (cur / 2));
                    else
                        prefixCut = max(prefixCut, 2 * (cur / 2) - 1);
                }
            }
        }
        string newS(s.substr(prefixCut));
        reverse(newS.begin(), newS.end());

        return newS + s;
    }

    void addBoundary(string &input, string &newInput)
    {
        newInput[0] = '$';
        for (int i = 0; i < input.length(); i++)
            newInput[2 * i + 2] = input[i];
        newInput[newInput.length() - 1] = '!';
    }
};

int main()
{
    string temp("aacecaaa");
    Solution s;
    cout << s.shortestPalindrome(temp);
}