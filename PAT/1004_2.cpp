#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100

struct Node
{
    int val;
    int height;
    set<int> child;

    Node(int val) : val(val) {}
};

Node *store[MAX_N];
int max_height;

void dfs(Node *root)
{
    if (root != nullptr)
    {
        for (int val : root->child)
        {
            store[val]->height = root->height + 1;
            max_height = max(max_height, store[val]->height);
            dfs(store[val]);
        }
    }
}

int main()
{
    int N, M;

    Node *root = new Node(1);
    store[1] = root;
    root->height = 0;

    while (cin >> N && N > 0)
    {
        cin >> M;

        for (int i = 0; i < M; i++)
        {
            int nonLeaf, count;
            cin >> nonLeaf >> count;

            int leaf;
            for (int j = 0; j < count; ++j)
            {
                cin >> leaf;
                if (store[nonLeaf] == nullptr)
                    store[nonLeaf] = new Node(nonLeaf);
                if (store[leaf] == nullptr)
                    store[leaf] = new Node(leaf);
                store[nonLeaf]->child.insert(leaf);
            }
        }

        max_height = 0;
        dfs(root);

        vector<int> result(max_height + 1, 0);
        result[0] = (root->child.empty() ? 1 : 0);
        for (int i = 2; i <= N; i++)
        {
            if (store[i] != nullptr)
            {
                if (store[i]->child.empty())
                    ++result[store[i]->height];
                delete store[i];
                store[i] = nullptr;
            }
        }
        root->child.clear();

        for (int i = 0; i < max_height; i++)
            cout << result[i] << " ";
        cout << result[max_height] << endl;
    }
}