/**
 * 200. 岛屿数量
 * link：https://leetcode-cn.com/problems/number-of-islands/
 */

/**
 * Method 1: DFS : 
 *      If a position where the value is 1, then use it as the starting node to start the dfs. 
 *      During the dfs, each searched 1 will be re-marked as 0.
 * Method 2: BFS
 *      If a position where the value is 1, then add it to the queue and start a bfs.
 *      During the bfs, each searched 1 will be re-marked as 0.
 * Method 3: Union Find
 *      Step 1 -> If a position where the value is 1, then its parent is itself
 *      Step 2 -> For each position where the value is 1, unite adjacent parent
 *      Step 3 -> When performing a unity operation, there parents being different means that they aren't in the same set, result - 1
 */
class Solution
{
private:
    int result = 0;

public:
    int findRoot(vector<int> &parent, int child)
    {
        if (parent[child] != child)
        {
            parent[child] = findRoot(parent, parent[child]);
        }
        return parent[child];
    }

    void unions(vector<int> &parent, int child1, int child2)
    {
        int root1 = findRoot(parent, child1);
        int root2 = findRoot(parent, child2);
        if (root1 < root2)
        {
            parent[root2] = root1;
            result--;
        }
        else if (root2 < root1)
        {
            parent[root1] = root2;
            result--;
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        if (m <= 0)
            return 0;
        int n = grid[0].size();

        vector<int> parent(m * n, 0);

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    parent[count] = count;
                }
                else
                {
                    parent[count] = -1;
                }
                count++;
            }
        }

        count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    if (i > 0 && grid[i - 1][j] == '1')
                        unions(parent, count, count - n);
                    if (j > 0 && grid[i][j - 1] == '1')
                        unions(parent, count, count - 1);
                    if (j < n - 1 && grid[i][j + 1] == '1')
                        unions(parent, count, count + 1);
                    if (i < m - 1 && grid[i + 1][j] == '1')
                        unions(parent, count, count + n);
                }
                count++;
            }
        }

        return result;
    }
};