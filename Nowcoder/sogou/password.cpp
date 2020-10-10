/**
 * [编程题]密码生成
 * https://www.nowcoder.com/questionTerminal/96bf0c548a094de7a05919e0b32b1a5a
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 12000000
#define MAX_M 200000

const long long MOD = 100000009;
inline long long sum(long long l, long long r) { return (l + r) * (r - l + 1) / 2; }

struct Opt
{
    int left;
    int right;
};

class SegmentTree
{
    int _store[MAX_N * 2];
    int _lazy[MAX_N * 2];
    int _count = 0;

    inline void pushup(int root)
    {
        _store[root] = _store[2 * root] + _store[2 * root + 1];
    }

    inline void pushdown(int root, int cur_l, int cur_r)
    {
        // Update current node
        if (_lazy[root] != 0)
        {
            _store[root] = (cur_r - cur_l + 1) * _lazy[root];
            if (cur_l != cur_r) // Not leaf node
            {
                _lazy[root * 2] = _lazy[root];     // mark left child as lazy
                _lazy[root * 2 + 1] = _lazy[root]; // mark right child as lazy
            }
            _lazy[root] = 0; // reset
        }
    }

public:
    void update(int root, int cur_l, int cur_r, int tar_l, int tar_r, int val)
    {
        // Out of range
        if (tar_l > tar_r || tar_r < cur_l || tar_l > cur_r)
            return;

        // Segment is fully within range
        if (cur_l >= tar_l && cur_r <= tar_r)
        {
            _lazy[root] = val;
            // pushdown(root, cur_l, cur_r);
            return;
        }

        // Update and propagation
        pushdown(root, cur_l, cur_r);

        int mid = (cur_l + cur_r) / 2;
        if (tar_l <= mid)
            update(2 * root, cur_l, mid, tar_l, tar_r, val);
        if (tar_r > mid)
            update(2 * root + 1, mid + 1, cur_r, tar_l, tar_r, val);
        pushup(root);
    }

    int query(int root, int cur_l, int cur_r, int tar_l, int tar_r)
    {
        // Update current node
        pushdown(root, cur_l, cur_r);

        // Out of range
        if (tar_l > tar_r || tar_r < cur_l || tar_l > cur_r)
            return 0;

        // Segment is fully within range
        if (cur_l >= tar_l && cur_r <= tar_r)
            return _store[root];

        int mid = (cur_l + cur_r) / 2;
        int result = 0;
        if (tar_l <= mid)
            result += query(root * 2, cur_l, mid, tar_l, tar_r); // Query left child
        if (tar_r > mid)
            result += query(root * 2 + 1, mid + 1, cur_r, tar_l, tar_r); // Query right child

        return result;
    }
};

SegmentTree s;
Opt op[MAX_M];
int discret[MAX_N];

int main()
{
    int size, round;
    cin >> size >> round;

    // Read input and discretization
    for (int i = 0; i < round; i++)
    {
        cin >> op[i].left >> op[i].right;
        discret[2 * i] = op[i].left;
        discret[2 * i + 1] = op[i].right;
    }
    sort(discret, discret + 2 * round);
    int discret_size = unique(discret, discret + 2 * round) - discret;

    // More discretization
    int more_discret = discret_size;
    for (int i = 1; i < discret_size; ++i)
    {
        if (discret[i] - discret[i - 1] > 1)
        {
            discret[more_discret++] = discret[i] - 1;
            discret[more_discret++] = discret[i - 1] + 1;
        }
    }
    sort(discret, discret + more_discret);
    discret_size = unique(discret, discret + more_discret) - discret;

    long long result = 0;
    for (int i = 0; i < round; i++)
    {
        op[i].left = lower_bound(discret, discret + discret_size, op[i].left) - discret;
        op[i].right = lower_bound(discret, discret + discret_size, op[i].right) - discret;
        s.update(1, 1, discret_size, op[i].left + 1, op[i].right + 1, i + 1);
    }

    for (int i = 0; i < discret_size - 1; i++)
        result = (result + sum(discret[i], discret[i + 1] - 1) * (1LL * s.query(1, 1, discret_size, i + 1, i + 1))) % MOD;
    result = (result + discret[discret_size - 1] * (1LL * s.query(1, 1, discret_size, discret_size, discret_size))) % MOD;

    cout << result << endl;
}