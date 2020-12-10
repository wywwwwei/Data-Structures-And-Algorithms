/**
 * 649. Dota2 参议院
 * link：https://leetcode-cn.com/problems/dota2-senate/
 */

/**
 * The goal is to find the opposing senator who is closest to you in the future.
 * 
 * Brute force:
 * Search directly from the next position
 * 
 * The senator at the front of the line votes first -> Queue:
 * We use two queue to respectively record the position of dire and radiant,
 * Senators who vote are added n (distinguish between the current round and the next round) and placed at the end
 */
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.length();

        // for (int i = 0; i < n; i = (i + 1) % n)
        // {
        //     if (senate[i] == 'R')
        //     {
        //         int j = i + 1;
        //         while (senate[j] != 'D')
        //         {
        //             j = (j + 1) % n;
        //             if (j == i)
        //                 return "Radiant";
        //         }
        //         senate[j] = 'O';
        //     }
        //     else if (senate[i] == 'D')
        //     {
        //         int j = i + 1;
        //         while (senate[j] != 'R')
        //         {
        //             j = (j + 1) % n;
        //             if (j == i)
        //                 return "Dire";
        //         }
        //         senate[j] = 'O';
        //     }
        // }
        // return "";

        queue<int> radiant, dire;
        for (int i = 0; i < n; i++)
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);

        while (!radiant.empty() && !dire.empty())
        {
            if (radiant.front() < dire.front())
                radiant.push(radiant.front() + n);
            else
                dire.push(dire.front() + n);
            radiant.pop();
            dire.pop();
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};