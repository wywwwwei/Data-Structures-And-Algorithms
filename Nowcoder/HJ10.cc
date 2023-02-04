/**
 * HJ10 字符个数统计
 * link：https://www.nowcoder.com/practice/eb94f6a5b2ba49c6ac72d40b5ce95f50
 */

#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main()
{
    string input;
    cin >> input;

    bool contains[128];
    memset(contains, false, sizeof(contains));

    int result = 0;
    for (const char c : input)
    {
        if (!contains[c])
        {
            ++result;
        }
        contains[c] = true;
    }
    cout << result << endl;
}