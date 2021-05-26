/**
 * 1008 Elevator
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
 */

#include <bits/stdc++.h>

using namespace std;

int N;

int solution(vector<int> &input)
{
    if (N <= 0)
        return 0;

    int result = input[0] * 6 + 5;
    for (int i = 1; i < N; ++i)
    {
        int diff = input[i] - input[i - 1];
        result += (diff > 0 ? diff * 6 : -diff * 4) + 5;
    }
    return result;
}

int main()
{
    cin >> N;

    vector<int> input(N);
    for (int i = 0; i < N; ++i)
        cin >> input[i];
    cout << solution(input) << endl;
}