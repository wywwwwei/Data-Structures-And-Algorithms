/**
 * 954. 二倍数对数组
 * link：https://leetcode-cn.com/problems/array-of-doubled-pairs/
 */

/**
 * If x is currently the array element with the least absolute value, it must pair with x*2 (x>=0) or x/2 (x<0)
 */

class Solution
{
public:
    bool canReorderDoubled(vector<int> &A)
    {
        map<int, int> count;

        for (const int &a : A)
            count[a]++;

        for (const auto &kv : count)
        {
            if (kv.second < 0)
                return false;
            else if (kv.second == 0)
                continue;
            if (kv.first < 0)
            {
                if (count.find(kv.first / 2) == count.end())
                    return false;
                count[kv.first / 2] -= kv.second;
            }
            else
            {
                if (count.find(kv.first * 2) == count.end())
                    return false;
                count[kv.first * 2] -= kv.second;
            }
        }

        return true;
    }
};