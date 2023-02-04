/**
 * HJ3 明明的随机数
 * link：https://www.nowcoder.com/practice/3245215fffb84b7b81285493eae92ff0
 */

#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main()
{
    int N, input;
    cin >> N;

    bool buckets[501];
    memset(buckets, false, sizeof(buckets));

    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        buckets[input] = true;
    }

    for (int i = 1; i <= 500; ++i)
    {
        if (buckets[i])
        {
            cout << i << endl;
        }
    }
}
