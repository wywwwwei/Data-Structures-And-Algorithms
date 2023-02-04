/**
 * HJ5 进制转换
 * link：https://www.nowcoder.com/practice/8f3df50d2b9043208c5eed283d1d4da6
 */

#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>

using namespace std;

unsigned int convert(const string &input)
{
    size_t len = input.length();
    // cut prefix
    if (len <= 2)
    {
        return 0;
    }
    unsigned int result = 0;
    auto parseChar = [](const char ch) -> int {
        if (isdigit(ch))
        {
            return ch - '0';
        }
        else if (isalpha(ch))
        {
            return 10 + tolower(ch) - 'a';
        }
        return 0;
    };
    for (size_t i = 2; i < len; ++i)
    {
        int power = 4 * (len - i - 1);
        result += parseChar(input[i]) * (1 << power);
    }
    return result;
}

int main()
{
    string input;
    while (cin >> input)
    { // 注意 while 处理多个 case
        cout << convert(input) << endl;
    }
}
