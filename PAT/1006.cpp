/**
 * 1006 Sign In and Sign Out
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
 */

#include <bits/stdc++.h>

using namespace std;

int M;

int parse_time()
{
    int time_h, time_m, time_s;
    scanf("%d:%d:%d", &time_h, &time_m, &time_s);
    return time_h * 10000 + time_m * 100 + time_s;
}

int main()
{
    cin >> M;

    int earliest = 240001, latest = -1;
    string earliest_id, latest_id;
    string id;
    for (int i = 0; i < M; ++i)
    {
        cin >> id;

        int cur = parse_time();
        if (cur < earliest)
        {
            earliest = cur;
            earliest_id = id;
        }

        cur = parse_time();
        if (cur > latest)
        {
            latest = cur;
            latest_id = id;
        }
    }
    cout << earliest_id << " " << latest_id << endl;
}