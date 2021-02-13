/**
 * 765. 情侣牵手
 * link：https://leetcode-cn.com/problems/couples-holding-hands/
 */

/**
 * Train of thought:
 * 1. 2 error seats needs 1 swap    ->      (a,b)->(b,a)
 * 2. 3 error seats needs 2 swap    ->      (a,b,c)->(c,a,b)
 * 3. 4 error seats needs 3/2 swap  ->      (a,b,c,d)->(b,a,d,c) or (a,b,c,d)->(c,a,d,b)
 *                                  ->   a <--> b  c <--> d      or  a -> c -> d -> b   and the number of arrow is the result
 * but because we dont (need to) know which of (2n,2n+1) pairs to be swapped, we use (2n,2n+1) as node n.
 * This is also consistent with the above summarized law that the result is the number of arrow 
 */

class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : findParent(parent, parent[x]);
    }

    bool merge(vector<int> &parent, int a, int b)
    {
        if (a == b)
            return false;
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        if (parent_a == parent_b)
            return false;
        parent[parent_a] = parent_b;
        return true;
    }

public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();

        vector<int> parent(n / 2);
        iota(parent.begin(), parent.end(), 0);

        int result = 0;
        for (int i = 0; i < n; i += 2)
            if (merge(parent, row[i] / 2, row[i + 1] / 2))
                ++result;

        return result;
    }
};