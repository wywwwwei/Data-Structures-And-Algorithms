/**
 * 1052. 爱生气的书店老板
 * link：https://leetcode-cn.com/problems/grumpy-bookstore-owner/
 */

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int n = customers.size();

        int notAngry = 0;
        int angry = 0;
        for (int i = 0; i < X; ++i)
        {
            if (grumpy[i] == 0)
                notAngry += customers[i];
            else
                angry += customers[i];
        }

        int maxAngry = angry;
        for (int i = X; i < n; ++i)
        {
            if (grumpy[i] == 0)
                notAngry += customers[i];
            else
                angry += customers[i];

            if (grumpy[i - X] == 1)
                angry -= customers[i - X];

            maxAngry = max(maxAngry, angry);
        }

        return notAngry + maxAngry;
    }
};