/**
 * [编程题]逛街
 * https://www.nowcoder.com/questionTerminal/35fac8d69f314e958a150c141894ef6a
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000
#define MAX_HEIGHT 100000

int descend[MAX_N];
int left_seen[MAX_N];
int right_seen[MAX_N];
int height[MAX_N];

int main()
{
    int buildings;
    cin >> buildings;
    for (int i = 0; i < buildings; i++)
        cin >> height[i];

    int idx = -1;
    for (int i = 0; i < buildings; i++)
    {
        left_seen[i] = idx + 1;
        while (idx >= 0 && height[i] >= descend[idx])
            idx--;
        descend[++idx] = height[i];
    }

    idx = -1;
    for (int i = buildings - 1; i >= 0; i--)
    {
        right_seen[i] = idx + 1;
        while (idx >= 0 && height[i] >= descend[idx])
            idx--;
        descend[++idx] = height[i];
    }

    for (int i = 0; i < buildings; i++)
    {
        cout << left_seen[i] + right_seen[i] + 1 << " ";
    }
}