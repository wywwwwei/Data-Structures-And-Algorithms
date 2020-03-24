/**
 * 892. 三维形体的表面积
 * link：https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
 */

/**
 * At the beginning, I wanted to calculate from the top view/side view/front view, 
 * but found that if there is a hole, it is not consistent.
 * e.g. [[2,2,2],[2,1,2],[2,2,2]]
 * 
 * So we need to calculate each cube
 * 1.Add
 * Calculate the contribution of each cube and add them.
 * 2.Subtraction
 * the number of cubes * 6 minus the number of contact surfaces * 2
 */
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int cubes = 0;
        int contact_surface = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                cubes += grid[i][j];

                if (grid[i][j] > 0)
                {
                    contact_surface += grid[i][j] - 1;
                    contact_surface += min(grid[i][j], (i > 0 ? grid[i - 1][j] : 0));
                    contact_surface += min(grid[i][j], (j > 0 ? grid[i][j - 1] : 0));
                }
            }
        }

        return cubes * 6 - contact_surface * 2;
    }
};