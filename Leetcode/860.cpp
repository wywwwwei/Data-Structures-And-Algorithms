/**
 * 860. 柠檬水找零
 * link：https://leetcode-cn.com/problems/lemonade-change/
 */

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int money5 = 0, money10 = 0;
        for (const int &bill : bills)
        {
            if (bill == 5)
                money5++;
            else if (bill == 10)
                money5--, money10++;
            else if (money10 > 0)
                money10--, money5--;
            else
                money5 -= 3;
            if (money5 < 0)
                return false;
        }
        // for (const int &bill : bills)
        // {
        //     if (bill == 5)
        //     {
        //         money5++;
        //     }
        //     else if (bill == 10)
        //     {
        //         money10++;
        //         if (--money5 < 0)
        //             return false;
        //     }
        //     else
        //     {
        //         if (money5 > 0 && money10 > 0)
        //             money5--, money10--;
        //         else if (money5 >= 3)
        //             money5 -= 3;
        //         else
        //             return false;
        //     }
        // }
        return true;
    }
};