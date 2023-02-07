/**
 * HJ8 合并表记录
 * link：https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int index, value;
    map<int, int> store;
    for (int i = 0; i < N; i++)
    {
        cin >> index >> value;
        store[index] += value;
    }

    for (const auto p : store)
    {
        cout << p.first << ' ' << p.second << endl;
    }
}