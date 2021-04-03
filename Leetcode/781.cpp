/**
 * 781. 森林中的兔子
 * link：https://leetcode-cn.com/problems/rabbits-in-forest/
 */

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> count;
        int result = 0;

        for (int answer : answers)
        {
            if (count[answer] > 0)
            {
                --count[answer];
            }
            else
            {
                result += answer + 1;
                count[answer] = answer;
            }
        }

        return result;
    }
};