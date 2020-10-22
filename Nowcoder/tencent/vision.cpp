/**
 * [编程题]视野争夺
 * https://www.nowcoder.com/questionTerminal/61e1e66e39f348cdb6495de91ac36a41
 */

#include <bits/stdc++.h>

using namespace std;

using dint = pair<int, int>;
#define MAX_N 100000

dint eyes[MAX_N];

int main()
{
    int eyes_num;
    int target;

    cin >> eyes_num >> target;
    for (int i = 0; i < eyes_num; i++)
    {
        cin >> eyes[i].first >> eyes[i].second;
    }

    //greedy
    sort(eyes, eyes + eyes_num, [](const dint &a, const dint &b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });

    int cur_distance = 0;
    int max_distance = 0;
    int result = 0;
    int i = 0;
    while (i < eyes_num)
    {
        if (eyes[i].first > cur_distance || target <= cur_distance)
            break;
        while (i < eyes_num && eyes[i].first <= cur_distance)
        {
            max_distance = max(max_distance, eyes[i].second);
            i++;
        }
        cur_distance = max_distance;
        result++;
    }
    cout << (cur_distance >= target ? result : -1) << endl;
}