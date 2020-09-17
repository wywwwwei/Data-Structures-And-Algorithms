/**
 * 685. 冗余连接 II 并查集
 * link：https://leetcode-cn.com/problems/redundant-connection-ii/
 */

/**
 * We define 
 *  - If the destination node has parent, the current edge causes a conflict
 *  - Otherwise, if the destination node and the source node are connected, the current edge creates a loop
 * additional directed edge can be:
 * 1. The non-root node points to the root node             ->  creates loop        -> delete the last edge that creates loop
 * 2. The non-root node points to another non-root node     ->  causes conflict   
 *      1) no loop                                                                  -> delete the edge that causes conflict
 *           1
 *          / \
 *         v   v
 *         2-->3
 *      2) loop                                                                     -> need to distinguish between 1->2 and 5->2
 *           1                                                                            1. when 1->2 earlier than 5->2
 *          / \                                                                              5->2 causes conflict and delete it
 *         v   v                                                                          2. when 1->2 later than 5->2
 *         2   3                                                                             5->2 (or other edges in the loop) creates a loop and
 *        / A                                                                                1->2 causes conflict, we need to delete
 *       v  |                                                                                the other edge points to 2 which does not cause conflict
 *       4  |
 *       |  |
 *       v  /
 *       5
 */

class Solution
{
    vector<int> parent;
    vector<int> ancestor;

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        ancestor.resize(n + 1);
        iota(parent.begin() + 1, parent.end(), 1);
        iota(ancestor.begin() + 1, ancestor.end(), 1);

        int conflict = -1;
        int cycle = -1;
        for (int i = 0; i < n; i++)
        {
            int src_node = edges[i][0];
            int dst_node = edges[i][1];

            if (parent[dst_node] != dst_node)
            {
                conflict = i;
            }
            else
            {
                parent[dst_node] = src_node;
                if (find(src_node) == find(dst_node))
                    cycle = i;
                else
                    merge(src_node, dst_node);
            }
        }

        //only one edge that creates loop
        if (conflict < 0)
            return edges[cycle];

        //only one edge that causes conflict
        if (cycle < 0)
            return edges[conflict];

        //Select the edge that causes the loop
        return {parent[edges[conflict][1]], edges[conflict][1]};
    }

    int find(int index)
    {
        return (index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]));
    }

    void merge(int u, int v)
    {
        ancestor[find(u)] = find(v);
    }
};