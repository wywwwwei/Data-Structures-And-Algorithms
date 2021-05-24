/**
 * 1005 Spell It Right
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
 */

#include <bits/stdc++.h>

using namespace std;

string N;
const char *num2str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string input)
{
    int result = 0;

    for (int i = 0; i < input.length(); ++i)
        result += input[i] - '0';

    return result;
}

int main()
{
    cin >> N;

    int result = solution(N);

    // reverse output
    int count = 1;
    for (int i = result; i >= 10; i /= 10)
        count *= 10;
    while (count > 0)
    {
        cout << num2str[(result / count) % 10];
        count /= 10;
        if (count > 0)
            cout << " ";
    }
    cout << endl;
}