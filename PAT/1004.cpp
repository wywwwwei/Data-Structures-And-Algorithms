/**
 * 1004 Counting Leaves
 * link: https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    vector<int> parent;
    while (cin >> N && N > 0)
    {
        cin >> M;

        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < M; i++)
        {
            int nonLeaf, count;
            cin >> nonLeaf >> count;

            int leaf;
            for (int j = 0; j < count; ++j)
            {
                cin >> leaf;
                parent[leaf] = nonLeaf;
            }
        }

        vector<int> result;

        set<int> q;
        q.insert(1);

        while (!q.empty())
        {
            set<int> next;
            set<int> child;

            for (int i = 1; i <= N; i++)
            {
                if (i != parent[i] && q.find(parent[i]) != q.end())
                {
                    child.insert(parent[i]);
                    next.insert(i);
                }
            }

            cout << q.size() - child.size();
            if (!next.empty())
                cout << " ";
            q.swap(next);
        }
        cout << endl;
    }
}