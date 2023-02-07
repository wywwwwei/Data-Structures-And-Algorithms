/**
 * NC52 有效括号序列
 * link：https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2
 */

#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Solution
{
  public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s)
    {
        if (s.length() % 2 != 0)
        {
            return false;
        }

        stack<char> store;
        auto pairs = [](char c) -> char {
            switch (c)
            {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return c;
            }
        };

        for (const char c : s)
        {
            char want = pairs(c);
            if (store.empty() || want == c)
            {
                store.push(c);
            }
            else if (want == store.top())
            {
                store.pop();
            }
            else
            {
                return false;
            }
        }

        return store.empty();
    }
};