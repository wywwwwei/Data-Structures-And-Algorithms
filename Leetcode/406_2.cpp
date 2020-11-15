/**
 * 406. 根据身高重建队列
 * link：https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 */

/**
 * Sort height in ascending order, k descending order, 
 * and put them into the vector in order. 
 * The height of people in the vector are less than the current value, 
 * so insert it directly into the k-th remaining empty position
 */

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = people.size();
        vector<vector<int>> result(n);
        for (const auto &person : people)
        {
            int pos = person[1] + 1;
            for(int i = 0;i < n;i++)
            {
                if(result[i].empty())
                    pos--;
                if(!pos)
                {
                    result[i] = person;
                    break;
                }
            }
        }

        return result;
    }
};