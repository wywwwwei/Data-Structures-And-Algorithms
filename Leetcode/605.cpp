/**
 * 605. 种花问题
 * link：https://leetcode-cn.com/problems/can-place-flowers/
 */

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // add boundary
        int zeros = 1;
        flowerbed.push_back(0);
        flowerbed.push_back(1);

        for (const int flower : flowerbed)
        {
            if (flower == 0)
                zeros++;
            else
            {
                n -= (zeros - 1) / 2;
                zeros = 0;
                if (n <= 0)
                {
                    flowerbed.pop_back();
                    flowerbed.pop_back();
                    return true;
                }
            }
        }

        flowerbed.pop_back();
        flowerbed.pop_back();
        return false;

        // int m = flowerbed.size();
        // for (int i = 0; i < m;)
        // {
        //     if (flowerbed[i] == 1)
        //         i += 2;
        //     else if (i == m - 1 || flowerbed[i + 1] == 0)
        //     {
        //         if (--n <= 0)
        //             return true;
        //         i += 2;
        //     }
        //     else
        //         i += 3;
        // }

        // return n <= 0;
    }
};