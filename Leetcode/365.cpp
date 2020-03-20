/**
 * 365. 水壶问题 裴蜀定理 
 * link：https://leetcode-cn.com/problems/water-and-jug-problem/
 */

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        //Separately discuss the two issues that do not require water and
        //more water is needed than the jug can hold
        return ((x + y) >= z && (z == 0 || z % __gcd(x, y) == 0));
    }
};