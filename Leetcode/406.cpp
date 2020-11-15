/**
 * 406. 根据身高重建队列
 * link：https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 */

/**
 * Sort height in descending order, k ascending order, 
 * and put them into the vector in order. 
 * The height of people in the vector are greater than or equal to the current value, 
 * so insert it directly into position k
 */

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> result;
        for (const auto &person : people)
        {
            result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};