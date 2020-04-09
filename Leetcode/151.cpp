/**
 * 151. 翻转字符串里的单词
 * link：https://leetcode-cn.com/problems/reverse-words-in-a-string/
 */

/**
 * Method 1: trim() -> reverse the entire string -> reverse each word
 * Method 2: deque
 * Method 3: stringstream - it's almost the same as method 2
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss;
        int rightmost = s.length() - 1;
        bool first = true;

        while (rightmost >= 0)
        {
            while (rightmost >= 0 && s[rightmost] == ' ')
                rightmost--;
            if (rightmost < 0)
                break;

            int right = rightmost;
            int left = rightmost;

            while (left >= 0 && s[left] != ' ')
                left--;

            if (first)
                first = false;
            else
                ss << " ";
            ss << s.substr(left + 1, right - left);

            rightmost = left;
        }
        return ss.str();
    }
};