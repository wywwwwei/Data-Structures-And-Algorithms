/**
 * [编程题]假期
 * https://www.nowcoder.com/questionTerminal/7cd9a140387e455a972e8fea0e74be2c
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100001

bool company[MAX_N];
bool gym[MAX_N];

int result[2][3];
enum State : int
{
    kCompany,
    kGym,
    kRest
};

int solve(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (company[i])
            result[1][kCompany] = min(result[0][kGym], result[0][kRest]);
        else
            result[1][kCompany] = INT_MAX;

        if (gym[i])
            result[1][kGym] = min(result[0][kCompany], result[0][kRest]);
        else
            result[1][kGym] = INT_MAX;

        result[1][kRest] = min(result[0][kRest], min(result[0][kCompany], result[0][kGym])) + 1;

        result[0][kCompany] = result[1][kCompany];
        result[0][kGym] = result[1][kGym];
        result[0][kRest] = result[1][kRest];
    }
    return min(result[1][kRest], min(result[1][kCompany], result[1][kGym]));
}

int main()
{
    int days;
    cin >> days;

    int tmp;
    for (int i = 1; i <= days; i++)
    {
        cin >> tmp;
        if (tmp)
            company[i] = true;
    }
    for (int i = 1; i <= days; i++)
    {
        cin >> tmp;
        if (tmp)
            gym[i] = true;
    }

    cout << solve(days) << endl;
}