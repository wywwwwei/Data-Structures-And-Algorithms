/**
 * 1009 Product of Polynomials
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344
 */

#include <bits/stdc++.h>>

using namespace std;

int main()
{
    int k1;
    cin >> k1;

    int input_n[10];
    float input_k[10];
    for (int i = 0; i < k1; ++i)
        cin >> input_n[i] >> input_k[i];

    float result[2001] = {0};
    int k2;
    cin >> k2;
    int count = 0;
    for (int i = 0; i < k2; ++i)
    {
        int cur_n;
        float cur_k;
        cin >> cur_n >> cur_k;
        for (int j = 0; j < k1; j++)
        {
            int n = input_n[j] + cur_n;
            if (result[n] == 0)
                ++count;
            result[n] += input_k[j] * cur_k;
            if (result[n] == 0)
                --count;
        }
    }

    cout << count;
    for (int i = 2000; i >= 0; i--)
        if (result[i] != 0)
            cout << " " << i << " " << fixed << setprecision(1) << result[i];
    cout << endl;
}