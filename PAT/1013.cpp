/**
 * 1013 Battle Over Cities
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int findParent(vector<int> &parent, int x)
{
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

void connect(vector<int> &parent, int a, int b)
{
    int a_parent = findParent(parent, a);
    int b_parent = findParent(parent, b);
    if (a_parent == b_parent)
        return;
    parent[a_parent] = b_parent;
}

int main()
{
    cin >> N >> M >> K;

    vector<int> parent(N + 1);

    int cityA, cityB;
    vector<vector<int>> edges(N + 1);
    for (int i = 0; i < M; ++i)
    {
        cin >> cityA >> cityB;
        edges[cityB].emplace_back(cityA);
    }

    int input, result;
    for (int i = 0; i < K; ++i)
    {
        cin >> input;
        iota(parent.begin(), parent.end(), 0);

        // union find
        for (int j = 1; j <= N; ++j)
        {
            if (j == input)
                continue;
            for (int edge : edges[j])
            {
                if (edge == input)
                    continue;
                connect(parent, j, edge);
            }
        }

        // calculate connectivity
        result = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (findParent(parent, j) == j)
            {
                ++result;
            }
        }

        // the city is occupied is one part and connect the rest (result-1) parts requires (result-2) edges
        cout << result - 2 << endl;
    }
}