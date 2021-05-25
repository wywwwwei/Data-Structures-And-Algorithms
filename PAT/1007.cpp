/**
 * 1007 Maximum Subsequence Sum
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
 */

#include <bits/stdc++.h>

using namespace std;

int K;

int main()
{
    cin >> K;
    vector<int> input(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> input[i];
    }

    int maximum = INT_MIN;
    int left = 0, right = 0;
    int cur_left = 0, cur_right = 0;
    int cur = 0;
    while (cur_right < K)
    {
        if (input[cur_right] + cur >= 0)
        {
            cur += input[cur_right++];
        }
        else
        {
            cur = 0;
            cur_left = ++cur_right;
            continue;
        }
        if (cur > maximum)
        {
            maximum = cur;
            left = input[cur_left];
            right = input[cur_right - 1];
        }
    }
    if (maximum < 0)
    {
        maximum = 0;
        left = input.front();
        right = input.back();
    }
    cout << maximum << " " << left << " " << right << endl;
}