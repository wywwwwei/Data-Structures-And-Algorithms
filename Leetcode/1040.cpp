/**
 * 1040. 移动石子直到连续 II
 * link：https://leetcode-cn.com/problems/moving-stones-until-consecutive-ii/
 */

/**
 * Maximum number of moves:
 * If the endpoint value is moved next to the nearest stone for the first time, 
 * then the stone can be moved to complete the current unoccupied position.
 * e.g.
 * [1,3,6,10] -> [1,3,5,6](number of unoccupied position = 2) -> [1,3,4,5] -> [1,2,3,4]
 * So maximum = max(number of unoccupied position) + 1 = max(stones[n-1]-stones[1]+1 - n,stones[n-2]-stones[0]+1 - n) + 1
 * maximum = max(stones[n-1] - stones[1] + 2 - n,stones[n-2] - stones[0] + 2 - n)
 * 
 * Minimum number of moves:
 * Find a sliding windows of size n and containing the most stones,
 * because normally, stones that are not in this window can be moved once to achieve.
 * A special case:
 * [1, 2, ..., n, >(n + 2)]
 * In this case, we can't move >(n+1) directly, we have to do 1 -> index(n+2), and then >(n+1) -> index(n+1)
 */

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());

        int n = stones.size();
        int result_max = max(stones[n - 2] - stones[0] - n + 2, stones[n - 1] - stones[1] - n + 2);
        int result_min = INT_MAX;

        for (int l = 0, r = 0; r < n; r++)
        {
            while (stones[r] - stones[l] > n - 1)
                l++;

            if (r - l == n - 2 && stones[r] - stones[l] == n - 2)
                result_min = min(result_min, 2);
            else
                result_min = min(result_min, n - (r - l + 1));
        }

        return {result_min, result_max};
    }
};