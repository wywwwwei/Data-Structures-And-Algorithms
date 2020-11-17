/**
 * 134. 加油站
 * link：https://leetcode-cn.com/problems/gas-station/
 */

/**
 * Loop 0... N-1 as the starting point i
 * when you can not arrive j in the first place,
 * then all gas station in [i,j] can not be the starting point
 * 
 * supposed the starting point is i and z is in [i,j) then sumOfGas(i,z) > sumOfCost(i,z)
 * we can not arrive j, so gas[j] < cost[j] and sumOfGas(i,j) < sumOfCost(i,j) 
 * then sumOfGas(z,j) < sumOfCost(z,j)
 * 
 * and we can keep checking from j + 1
 */
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;

        int gasSum, costSum;
        while (i < n)
        {
            gasSum = 0;
            costSum = 0;
            int runs = 0;
            while (runs < n)
            {
                int cur = (i + runs) % n;
                gasSum += gas[cur];
                costSum += cost[cur];
                if (costSum > gasSum)
                    break;
                runs++;
            }
            if (runs == n)
                return i;
            else
                i = i + runs + 1;
        }

        return -1;
    }
};