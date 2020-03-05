/**
 * 1003 Emergency
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376
 */

#include <iostream>

using namespace std;

#define MAX_LEN 1000000
int start, ending;
int city_num, road_num;
int hands_num[500];
int roads[500][500];
bool visited[500];

void Dijkstra()
{
    int distance[500];
    int road_num[500];
    int max_hand_num[500];

    max_hand_num[start] = hands_num[start];
    road_num[start] = 1;

    for (int i = 0; i < city_num; i++)
    {
        distance[i] = MAX_LEN;
    }
    distance[start] = 0;

    for (int i = 0; i < city_num; i++)
    {
        int min_dis = MAX_LEN;
        int shortest_city = -1;
        for (int j = 0; j < city_num; j++)
        {
            if (!visited[j] && distance[j] < min_dis)
            {
                min_dis = distance[j];
                shortest_city = j;
            }
        }

        if (shortest_city == -1)
        {
            cout << 0 << " " << 0;
            return;
        }
        visited[shortest_city] = true;

        for (int j = 0; j < city_num; j++)
        {
            if (!visited[j])
            {
                if (distance[j] > distance[shortest_city] + roads[shortest_city][j])
                {
                    distance[j] = distance[shortest_city] + roads[shortest_city][j];
                    road_num[j] = road_num[shortest_city];
                    max_hand_num[j] = max_hand_num[shortest_city] + hands_num[j];
                }
                else if (distance[j] == distance[shortest_city] + roads[shortest_city][j])
                {
                    road_num[j] += road_num[shortest_city];
                    max_hand_num[j] = ((max_hand_num[shortest_city] + hands_num[j] > max_hand_num[j]) ? (max_hand_num[shortest_city] + hands_num[j]) : max_hand_num[j]);
                }
            }
        }
    }
    cout << road_num[ending] << " " << max_hand_num[ending];
}

int main()
{
    cin >> city_num >> road_num >> start >> ending;
    for (int i = 0; i < city_num; i++)
    {
        cin >> hands_num[i];
    }
    for (int i = 0; i < city_num; i++)
    {
        for (int j = 0; j < city_num; j++)
        {
            roads[i][j] = MAX_LEN;
        }
    }
    for (int i = 0; i < road_num; i++)
    {
        int tempa, tempb, tempc;
        cin >> tempa >> tempb >> tempc;
        roads[tempa][tempb] = tempc;
        roads[tempb][tempa] = tempc;
    }
    Dijkstra();
}